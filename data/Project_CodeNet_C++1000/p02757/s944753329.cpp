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

int main(){
  int n, p;cin>>n>>p;
  string s;cin>>s;

  if(p==2 || p==5){
    ll result=0;
    rep(i, n)if((s[i]-'0')%p==0){
      result += i+1;
    }

    cout<<result<<endl;

    return 0;
  }

  vector<int>a;
  rep(i, n)a.push_back(s[i]-'0');
//rep(i, n)cout<<a[i]<<' ';cout<<endl;
  int c=1;
  rrep(i, n)a[i]=(a[i]*c)%p, c= c*10%p;

//rep(i, n)cout<<a[i]<<' ';cout<<endl;
  rrep1(i, n-1)a[i-1]=(a[i-1]+a[i])%p;
//rep(i, n)cout<<a[i]<<' ';cout<<endl;
  map<ll, ll> m;
  for(auto cc:a)m[cc]++;
  ll result = 0;
  for(auto p:m){
    result += p.second*(p.second-1)/2;
  }
  cout<<result+m[0]<<endl;

  return 0;
}