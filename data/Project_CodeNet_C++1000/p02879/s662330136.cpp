#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin>>A>>B;
  bool a= A<10;
  bool b= B<10;
  if(a&&b) cout<<A*B<<endl;
  else cout<<"-1"<<endl;
}