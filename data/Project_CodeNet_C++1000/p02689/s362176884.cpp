#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  int n,m;cin >>n>>m;
  vector<int> h(n);
  for(int i=0;i<n;++i) cin >> h[i];
  vector<bool> isgood(n,true);
  for(int j=0;j<m;++j){
    int a,b;cin>>a>>b;
    if(h[a-1]>h[b-1]){
      isgood[b-1] = false;
    } else if(h[a-1]<h[b-1]) {
      isgood[a-1] = false;
    } else {
      isgood[a-1] = false;
      isgood[b-1] = false;
    }
  }
  int out =0;
  cout << count(isgood.begin(), isgood.end(), true) << endl;
  return 0;
}