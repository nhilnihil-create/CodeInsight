#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m=0; cin>>n;
  vector<int> a(n);
  vector<int> e(n);
  vector<vector<int>> x(16,vector<int>(16)); //int x[16][16];
  vector<vector<int>> y(16,vector<int>(16)); //int y[16][16];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int ii = 0; ii < a[i]; ii++) {
      cin >> x[i][ii] >> y[i][ii];
    }
  }
  int t,f;
  for(int bit=0;bit<(1<<n);bit++){ //n個のものをそれぞれ選ぶor選ばないの2択
    t=0; f=0;
    for(int i=0;i<n;i++){
      if(bit & (1 << i)){ //bitのときiは選ばれているか
        e[i]=1;
      }else{
        e[i]=0;
      }
    }
    for(int i=0;i<n;i++){
      if(e[i]==1){
        for(int ii=0;ii<a[i];ii++){
          if(e[x[i][ii]-1]!=y[i][ii]){
            ii=a[i]+1; f=2;
          }
        }
        t++;
      }
    }
    if(f==2) continue;
    m=max(m,t);
  }
  cout<<m<<endl;
}