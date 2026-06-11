/*
* ID: juryc
* PROG: Poor
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c; cin>>a>>b>>c;
set<int> st;
st.insert(a); st.insert(b);  st.insert(c); 
int sz=st.size();
if(sz==2) cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}