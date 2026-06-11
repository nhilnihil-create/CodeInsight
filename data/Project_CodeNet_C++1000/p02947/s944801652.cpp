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
ll nc2(int x){
  return x*(x-1)/2;
}
int main()	{
  int n;
  cin>>n;
  vector<string> s(n);
  map<string,int>mp;
  rep(i,n){
    cin>>s[i];
    sort(rall(s[i]));
  }
  rep(i,n){
    mp[s[i]]++;
  }
  ll ans=0;
  for(auto x:mp){
    int t=x.sc;
    ans+=(ll)t*(t-1)/2;
  }
  cout<<ans<<endl;
}