#include <bits/stdc++.h>
using namespace std;

int main ()
{
int A1,A2,A3;
cin>>A1>>A2>>A3;
if(A1!=0&&A2!=0&&A3!=0&&A1<=13&&A2<=13&&A3<=13){
if(A1+A2+A3>=22){
    cout<<"bust";
}
else{
    cout<<"win";
}
}
  return 0;
}