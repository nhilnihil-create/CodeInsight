#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  if(a<b){
    cout<<'0';
  } else if(a<2*b){
    cout<<'0';
  } else {
    cout<<a-(2*b)<<endl;
  }
}