#include <bits/stdc++.h>
#define rep(i,s,n) for (int i=s;i<n;++i)
#define drep(i,s,n) for (int i=n;i>=s;--i)
#define all(x) (x).begin(),(x).end()
#define rall(a) (a).rbegin(),(a).rend()
#define print(x) cout<<(x)<<endl
using namespace std;
typedef long long ll;
int gcd(int a,int b)
{if (a%b == 0) return(b);
 else          return(gcd(b,a%b));}
int lcm(int a,int b)
{return a*b/gcd(a,b);}
void printv(vector<auto> v) {cout<<'[';rep(i,0,v.size()){cout<<v[i]<<',';}cout<<']'<<endl;}
void printvv(vector<vector<auto>> vv)
{
  cout<<'['<<endl;
  rep(q,0,vv.size()){cout<<'[';rep(p,0,vv.at(q).size())cout<<vv.at(q).at(p)<<',';cout <<']'<<endl;}
  cout<<']'<<endl;
}
void solve(); int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}
int step_x[] = {-1,0,0,1};
int step_y[] = {0,-1,1,0};
const long long INF = 1000000;
//------------------------------------------------------------
ll n;
void solve()
{
    cin >> n;
    vector<pair<ll,ll>> v(n);
    rep(i,0,n) {cin >> v[i].first; v[i].second=i;}

    vector<vector<ll>> dp(n+2, vector<ll>(n+2, -1));
    dp[0][0]=0;

    sort(rall(v));

    rep(i, 0, n)
    {
      rep(l,0,i+1)
      {
        if(dp[i][l]>=0)
        {
          dp[i+1][l+1] = max(dp[i+1][l+1], dp[i][l]+v[i].first*abs(v[i].second-l));
          dp[i+1][l]   = max(dp[i+1][l], dp[i][l]+v[i].first*abs((n-1)-(i-l)-v[i].second));
        }
      }
    }

    ll ans = -1;
    rep(i,0,n) ans = max(ans, dp[n][i]);

    print(ans);

    return;
}

