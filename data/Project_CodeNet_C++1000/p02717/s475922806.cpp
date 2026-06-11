#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c,d;
cin>>a>>b>>c;
if(a>=1&&a<=100&&b>=1&&b<=100&&c>=1&&c<=100){
d = a;
a = b;
b = d;
d = a;
a = c;
c = d;
cout<<a<<" "<<b<<" "<<c<<endl;}

return 0;}
