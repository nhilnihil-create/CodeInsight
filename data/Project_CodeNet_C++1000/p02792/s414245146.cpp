#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD=1e9+7;
const int INF32=1<<30;
const ll INF64=1LL<<60;

void solve(){
  int n; cin >>n;
  int c[10][10]; memset(c,0,sizeof(c));
  for(int i=1; i<=n; i++){
    string s=to_string(i); char a=s[0];
    int x=a-'0',y=i%10;
    c[x][y]++;
  }
  int ans=0;
  for(int i=1; i<10; i++) for(int j=1; j<10; j++) ans+=c[i][j]*c[j][i];
  cout <<ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
return 0;}