#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;cin>>n;
  set<int> st;
  int temp;
  for(int i=1;i<=n;i++){
    cin>>temp;
    if(st.find(temp)!=st.end()){
      cout<<"NO\n";
      return 0;
    }
    st.insert(temp);
  }
  cout<<"YES\n";
  return 0;
}