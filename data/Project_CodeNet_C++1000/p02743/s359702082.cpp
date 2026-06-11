#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a,b,c;
  cin>>a>>b>>c;
  cout<<(a+b<c&&4*a*b<(c-a-b)*(c-a-b)?"Yes":"No")<<endl;
}