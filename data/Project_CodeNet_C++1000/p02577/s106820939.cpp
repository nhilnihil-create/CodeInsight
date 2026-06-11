#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
#define Max(a) (*max_element(ALL(a)))
#define Min(a) (*min_element(ALL(a)))
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;cin>>s;
  ll ans = 0;
  for(auto c:s)ans += (c-'0');
  if(ans%9)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
}
