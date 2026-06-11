
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> P;
#define rep(i,n) for(ll i=0;i<n;++i)
const int INF=1001001001;
int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  rep(i,n){
    cin>>a[i];
    a[i]--;
  }
  vector<ll> s(n+1);
  rep(i,n){
    s[i+1]=(s[i]+a[i])%k;
  }
  ll cnt=0;
  map<int,int> mp;
  queue <int> q;
  rep(i,n+1){
    int now=s[i];
  //  cout<<i<<'i'<<now<<'n'<<endl;
   cnt+=mp[now];
   mp[now]++;
   q.push(now);
   if (q.size()==k){
     mp[q.front()]--;
     q.pop();
   }


  }
  cout<<cnt;
}
