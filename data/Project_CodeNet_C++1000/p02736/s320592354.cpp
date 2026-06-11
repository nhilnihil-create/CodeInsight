#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
#define endl '\n'
using ll = long long;
#define int ll
using db = long double;
using ii = pair<int, int>;

const int N = 1e5 + 5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;
string s;
int n;
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
  cin >> n >> s;
  bool f = false;
  for(auto &c:s)c-='1',f|=(c==1);

  f(i,0,n)if(s[i]==2)s[i]=!f;

  vector<int>cnt(1000*1000+5);

  f(i,1,1000*1000+5){
    cnt[i]=cnt[i-1]+__builtin_ctz(i);
  }

  int ans = 0;
  f(i,0,n)if(cnt[n-1]<=cnt[i]+cnt[n-i-1])ans^=s[i];

  if(!f)ans*=2;
  cout<<ans<<'\n';



  return 0;
}
