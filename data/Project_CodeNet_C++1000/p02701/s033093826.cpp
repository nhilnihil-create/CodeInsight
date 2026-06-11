#include<bits/stdc++.h>
using namespace std;
int main(void){
  int i,n;cin>>n;
  string s;
  set<string> S;
  for(i=0; i<n; ++i){ cin>>s; S.insert(s);}
  cout<<S.size()<<endl;
  return 0;
}