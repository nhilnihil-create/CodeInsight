#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;cin>>a>>b;
  int S=0,T=0;
  string X,Y;
  for(int i=0;i<b;i++) S+=a*pow(10,i);
  for(int j=0;j<a;j++) T+=b*pow(10,j);
  X=to_string(S);Y=to_string(T);
  if(X<=Y) cout<<X<<endl;
  else cout<<Y<<endl;
}