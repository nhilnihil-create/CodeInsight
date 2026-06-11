#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define ull unsigned long long
#define pii pair<int,int>
#define pb(x) push_back(x)
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define drep(i,a,b) for(int i=(a); i>=(b);i--)
 
const int maxn = 1e5 + 5;
const int maxm = 5000 + 5;
const int MOD = 1e9 + 7;
const int N = 1005;

int n;
int a[maxn * 2],sum[maxn * 2];
char s[maxn * 2];


int main()
{
   ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
   // #ifndef ONLINE_JUDGE 
   //freopen("input.txt", "r", stdin);
   //#endif // ONLINE_JUDGE 
   cin >> n >> (s + 1);
   a[1] = 1;
   rep(i,2,2*n){
        if(s[i] == s[i - 1]) a[i] = (a[i - 1] == 1) ? -1 : 1;
        else  a[i] = (a[i - 1] == 1) ? 1 : -1;
   } 
   rep(i,0,2*n) sum[i] = sum[i - 1] + a[i];
   if(s[1] == 'W' || s[2*n] == 'W' || sum[2*n]) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
   rep(i,1,2*n) {
      if(i <= n) ans = ans * i % MOD;
      if(a[i] == 1) continue;
      ans = ans * sum[i - 1] % MOD;
   }
   cout << ans << endl;
   return 0;
}