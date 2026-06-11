#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define L INT_MIN
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;

int main()
{
  fastio;
  string s;
  cin>>s;
  int md=2019;
  int n=s.length();
  vector<ll> count_suffix(2019);
  ll ans=0;
  ll pot=1;
  ll suffix=0;
  count_suffix[suffix]++;
  for(int i=n-1;i>=0;i--)
  {
    int digit=s[i]-'0';
    suffix=(suffix + digit*pot)%md;
    pot=pot*10%md;
    ans+=count_suffix[suffix];
    count_suffix[suffix]++;
  }
  cout<<ans<<endl;
}
  