#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  int n,k;cin >> n>>k;
  vector<bool> v(n,false);
  int out = n;
  for(int i=0;i<k;++i){
    int d; cin >>d;
    for(int j=0;j<d;++j){
      int t;cin >>t;
      if(!v[t-1]){
        --out;
        v[t-1] = true;
      }
    }
  }
  cout << out << endl;

  return 0;
}
