#include<bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
#define int long long

signed main(){
  int N, M;
  cin >> N >> M;
  int s[1000], c[1000];
  rep(i,M){
    cin >> s[i] >> c[i];
  }
  rep(i,1000){
    bool a = true;
    rep(j,M){
        if(to_string(i)[s[j]-1] != to_string(c[j])[0]){a = false;break;}
    }
    if(a){if(to_string(i).length() == N){cout << i;return 0;}}
  }
  cout << -1;
}

