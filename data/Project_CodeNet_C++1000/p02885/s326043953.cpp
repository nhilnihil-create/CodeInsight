#include <bits/stdc++.h>
using namespace std;

int main ()
{
int A,B;
cin>>A>>B;
if(A!=0&&B!=0&&A<=100&&B<=100){
if(A>=(2*B)){
    cout<<A-(2*B);
}
else{
    cout<<"0";
}
}
return 0;
}