#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  set<char>st;
  st.insert(s[0]);
  st.insert(s[1]);
  st.insert(s[2]);
  st.insert(s[3]);
  if(st.size()==2)
    cout<<"Yes";
  else
    cout<<"No";
  
}