#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
typedef long long ll;
#define _GLIBCXX_DEBUG
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<char> cvec;
typedef vector<double> dvec;
typedef pair<ll, ll> LP;
typedef tuple<ll, ll, ll> LT;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define fs first
#define sc second
int main()	{
  int n;
  cin>>n;
  map<string,int>mp;
  rep(i,n){
    string s;
    cin>>s;
    sort(all(s));
    mp[s]++;
  }
  ll ans=0;
  for(auto x:mp){
    ll a=x.sc;
    ans+=a*(a-1)/2;
  }
  cout<<ans<<endl;
}