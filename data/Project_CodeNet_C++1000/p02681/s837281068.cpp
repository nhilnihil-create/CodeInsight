#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  string T;
  cin>>S>>T;
  T=T.erase(S.size());
  if(S == T) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}