#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i<(n);i++)
#define fore(i,a) for(auto &i:a)
#define debug(a,b) cout << "debug : " << a << " , "<< b << endl
using ll=long long;
const ll INF=1LL<<60;
const ll mod=1E9+7;


const float unit=0.1f;

int main(){
  int h1,m1,h2,m2,k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  cout << 60*(h2-h1)+(m2-m1)-k;
}
