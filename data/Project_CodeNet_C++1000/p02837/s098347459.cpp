#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n,vector<int>(n,-1));
  for(int i=0;i <n;i++){
    int A; cin >> A;
    for(int j = 0;j < A;j++){
      int x,y;
      cin >> x >> y;
      a.at(i).at(x-1) = y;
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1<<n); ++bit) {
    vector<int> s(n,0);
    int flag = 1;
    int buf = 0;
    for (int i = 0; i < n; ++i) {
      if (bit & (1<<i)) { 
        s.at(i) = 1;
      }
    }
    for(int i = 0;i < n;i++){
      if(s.at(i) == 1){
        buf++;
        for(int j = 0;j < n;j ++){
          if(a.at(i).at(j) == -1){continue;}
          if(a.at(i).at(j) != s.at(j)){
            //cout << i << endl;
            //cout << s.at(0) << s.at(1) << s.at(2) << endl;
            flag = 0; break;}
        }
      }
    }
    if(flag){ans = max(ans,buf);}
  }
  cout << ans << endl;
}