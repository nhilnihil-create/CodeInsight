#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  int x,n;cin >> x>>n;
  set<int> st;
  for(int i=0;i<n;++i){
    int t;cin>>t;
    st.insert(t);
  }
  int out;
  if(st.find(x)==st.end()){
    out = x;
  } else {
    int d=1;
    while(true){
      int p = x + d;
      int m = x - d;
      if(st.find(m)==st.end()){
        out = m;
        break;
      } else {
        if(st.find(p)==st.end()){
          out = p;
          break;
        }
      }
      ++d;
    }
  }
  cout << out << endl;
  return 0;
}
