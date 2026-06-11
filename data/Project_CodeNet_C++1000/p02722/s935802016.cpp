#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

vector<ll> divisor(ll n){
  vector<ll> res;
  for(ll i=1; i*i<=n; i++){
    if(n%i==0){
      res.push_back(i);
    if(i!=n/i)res.push_back(n/i);
    }
  }
  return res;
}

int main(){
  ll n, cn; cin>>n;
  cn=n;

  int result1=0;
  auto nums = divisor(n);
  for(auto t: nums){
    if(t==1)continue;

    ll ccn = n;
    while(ccn%t==0 && ccn>=t)ccn/=t;
    if(ccn%t==1)result1++;
  }

  n--;
  map<ll, ll> m;
  for(ll i=2; i*i<=n; i++){
    while(n%i==0){
      m[i]++;
      n /= i;
    }
  }
  if(n>1)m[n]++;

  int result=1;
  for(auto p:m){
    result*=(p.second+1);
  }
  result--; // 1

  cout<<result+result1<<endl;
  
  return 0;
  
  cout<<result<<' '<<result1<<endl;


  for(auto t: nums)cout<<t<<' ';cout<<endl;
  cout<<endl;
  for(auto p: m)cout<<p.first<<' '<<p.second<<endl;

  return 0;
}
