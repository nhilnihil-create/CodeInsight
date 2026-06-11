#include <bits/stdc++.h>
using namespace std;
int main(){
int a,b,c,x,y,z;
cin>>a>>b>>c;
x=a;
y=b;
z=c;
b=x;
a=z;
c=y;
cout<<a<<' '<<b<<' '<<c;
return 0;
}