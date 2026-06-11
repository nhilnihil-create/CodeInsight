#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  int n;cin>>n;
  string s;cin >>s;
  vector<int> vr(n),vw(n);
  int cr=0;
  int cw=0;
  for(int i=0;i<n;++i){
    auto tmp = s.substr(i,1);
    if(tmp=="R"){
      ++cr;
    } else {
      ++cw;
    }
    vr[i] = cr;
    vw[i] = cw;
  }
  cout << cr - vr[cr-1] << endl;
  return 0;
}
