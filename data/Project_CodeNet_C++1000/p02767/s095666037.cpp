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

  std::vector<ll> x(n);
  rep(i,n) cin >> x.at(i);
  sort(all(x));

  ll hp=1000000000000000000LL,sum;
    for(ll i=1;i<100;i++){
      sum=0;
      for(ll j=0;j<n;j++){
        sum+=(x.at(j)-i)*(x.at(j)-i);

      }

        hp=min(sum,hp);
    }

  cout << hp << endl;

}
