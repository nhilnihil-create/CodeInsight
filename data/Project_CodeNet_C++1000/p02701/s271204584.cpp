#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  set<string> st;
  rep(i,n){
    string s;cin>>s;
    st.insert(s);
  }
  int ans=st.size();
  cout<<ans<<endl;
}