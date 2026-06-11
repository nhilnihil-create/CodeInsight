#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
      long double a,b,c;
       cin>>a>>b>>c;
    ll ok=0;
      long double e=1.0E-15;
       //cout<<e<<endl;
        if((sqrt(a)+sqrt(b)+e)<sqrt(c))ok=1;
    printf(ok==1? "Yes\n":"No\n");
}