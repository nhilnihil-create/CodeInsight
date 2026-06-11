#include<bits/stdc++.h>
using namespace std;

int main(){
  
  long long Xfmin = 0, N, i, ix = 0, cnt = 1;
  cin >> N;
  
  vector<pair<long long, long long>> SF(N);
  for(i = 0; i < N; i++){
    long long X, L; 
    cin >> X >> L;
    SF[i].second = X - L; SF[i].first = X + L;
  }
  sort(SF.begin(), SF.end());
    
  Xfmin = SF[0].first;
  while(true){
    
    bool flag = false;
    for(i = ix + 1; i < N; i++){
      if(Xfmin <= SF[i].second){
        ix = i;
        Xfmin = SF[i].first;
        cnt++;
        flag = true;
        break;
      }
    }
    if(!flag)break;
  }
  cout << cnt << endl;
  return 0;
}