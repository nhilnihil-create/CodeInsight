#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define sz(x) ll(x.size())
using namespace std;

int main() {
  ll m,D=0,S=0,d,c;
  cin >> m;
  rep(i,m){
  	cin >> d >> c;
    D+=c;
    S+=d*c;
  }
  	cout << D-1+(S-1)/9 << endl;
}
