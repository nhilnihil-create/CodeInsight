#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2)

int main()
{
  string s;
  cin>>s;
  map<ll,ll> m;
  
  reverse(s.begin(),s.end());
  
  ll n=0;
  ll p=1;
  for (int i=0;i<s.size();i++)
  {
    n = (s[i]-'0')*p + n;
    //cout<<n<<endl;
    p *= 10;
    p %= 2019;
    n %= 2019;
    m[n%2019]++;
  }
  
  ll ans =0;
  for(auto i=m.begin();i!=m.end();i++)
  {
     ans += (i->second)*(i->second-1)/2;
  }
  ans += m[0];
  
  cout<<ans<<endl;
}