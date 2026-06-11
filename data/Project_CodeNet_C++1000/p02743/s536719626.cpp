#include<bits/stdc++.h>
#define ll 	long long
#define pb push_back
#define mp make_pair
using namespace std;

int main(){

long double a,b,c,d=0,e=0;
cin>>a>>b>>c;

d=sqrt(a)+ sqrt(b);
e=sqrt(c);
if(c-a-b>0)
{

if(4*a*b< (c-a-b)*(c-a-b)) cout<<"Yes\n";

else cout<<"No\n";
}
else cout<<"No\n";
    return 0;
}
 