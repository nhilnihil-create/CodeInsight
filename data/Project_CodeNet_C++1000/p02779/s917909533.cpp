#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> a(n);
  set<int> st;
  rep(i,n){
    cin>>a[i];
    st.insert(a[i]);
  }
  if(st.size()==n)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}