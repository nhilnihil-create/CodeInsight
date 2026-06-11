#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, M;
  vector<int> w, h;
  vector<int> wsum, hsum;
  while(cin >> N >> M, N | M){
    map<int, int> hm, wm;
    h.resize(N);  hsum.resize(N+1);
    w.resize(M);  wsum.resize(M+1);
    hsum[0] = wsum[0] = 0;
    for(int i=0; i < N; i++){
      cin >> h[i];
      if(i != 0){
        hsum[i+1] = hsum[i] + h[i];
      }else{
        hsum[i+1] = h[i];
      }
    }
    for(int i=0; i < M; i++){
      cin >> w[i];
      if(i != 0){
        wsum[i+1] = wsum[i] + w[i];
      }else{
        wsum[i+1] = w[i];
      }
    }


    for(int i=0; i < M+1; i++){
      for(int j=i+1; j < M+1; j++){
        int a = wsum[j] - wsum[i];
        if(wm.find(a) == wm.end()){
          wm[a] = 1;
        }else{
          wm[a]++;
        }
      }
    }
    int ans = 0;
    for(int i=0; i < N+1; i++){
      for(int j=i+1; j < N+1; j++){
        int a = hsum[j] - hsum[i];
        if(wm.find(a) != wm.end()){
          ans += wm[a];
        }
      }
    }
  cout << ans << endl;
  }
  return 0;
}