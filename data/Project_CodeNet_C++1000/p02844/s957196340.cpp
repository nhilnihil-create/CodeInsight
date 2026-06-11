#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long dp[110][110000];
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n, ans = 0;
  string s;
  cin >> n >> s;
  rep(i,1000){
    int a[3] = { i/100, (i/10)%10, i%10};
    int f = 0;
    rep(j, n){
      if(s[j]==('0'+a[f])) f++;
      if(f==3) break;
    }
    if(f==3) ans++;
  }
  cout << ans << endl;
}
