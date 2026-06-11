#include<iostream>
#include<cmath>
using namespace std;
int main(){
long a,b,c,d;
cin>>a>>b>>c>>d;
long long k=max(a*c,a*d);
long long j=max(b*c,b*d);
long long val=max(k,j);
cout<<val;


return 0;
}
