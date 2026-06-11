#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll n;
  cin >> n;

  std::vector<ll> a(n);
  rep(i,n-1) cin >> a.at(i);

  map<ll,ll> x;


  ll number;
  for(ll i=0;i<n-1;i++){
    number=a.at(i);
    x[number]=x[number]+1;
  }

  for(ll i=1;i<n+1;i++){
    cout << x[i] << endl;
  }


  }
