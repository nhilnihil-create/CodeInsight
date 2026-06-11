#include<bits/stdc++.h>
using namespace std;
int main()
{
    long double a,b,c;
    cin>>a>>b>>c;
    //long long int aa=a+b+2*((long double)sqrt(a*b));
    long double aa1=a+b+2*((long double)sqrt(a*b));
    //cout<<aa<<" "<<fixed<<setprecision(10)<<aa1;
    if(aa1<c)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
