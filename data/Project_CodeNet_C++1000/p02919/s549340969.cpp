#include<bits/stdc++.h>
using namespace std;
int main(){
  long ans=0;
  int n;cin >> n;
  vector<long> p(n+1,-1);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    p[a]=i;
  }
  set<long> st;
  st.insert(-1);
  st.insert(-2);
  st.insert(n);
  st.insert(n+1);
  for(int i=n;i>0;i--){
    auto right1 = st.lower_bound(p[i]);
    auto right2 = right1;
    right2++;
    auto left1 = right1;
    left1--;
    auto left2 = left1;
    left2--;
    if(*right2<n+1){
      ans += (*right2 - *right1) * (p[i] - *left1) * i;
    }
    if(*left2>-2){
      ans += (*left1 - *left2) * (*right1 - p[i]) * i;
    }
    st.insert(p[i]);
  }
  cout << ans << endl;
}