#include<iostream>
#include<set>
using namespace std;
int main(){
  set<int>st;
  int n,f;
  cin>>n;
  for (int i=0; i<n;i++){
    cin>>f;
    st.insert(f);
  }
  if(n==st.size()) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}