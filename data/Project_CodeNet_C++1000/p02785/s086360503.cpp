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
  ll n,k;
  cin >> n >> k;

std::vector<ll> h(n);

rep(i,n) cin >> h.at(i);

sort(all(h));

ll atack=0;
for(ll i=0;i<n-k;i++){
  atack+=h.at(i);
}

cout << atack << endl;

}