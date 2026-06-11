#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int>H(N);
  for (int i=0; i<N; i++)
    cin >> H.at(i);
  
  int max=0,cnt=0;
  for (int i=0; i<N-1; i++){
    if (H.at(i) >= H.at(i+1)){
      cnt++;
    }else{
      if (max < cnt)
        max = cnt;
      cnt = 0;
    }
  }
  if (max < cnt)
    max = cnt;
  cout << max << endl;
}
