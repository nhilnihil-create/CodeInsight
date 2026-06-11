#include <bits/stdc++.h>
using namespace std;
int main(){
  string a,b,c;
  int d,e;
  cin>>a>>b>>d>>e>>c;
  cout<<(a==c? d-1:d)<<" "<<(a==c? e:e-1)<<endl;
}
