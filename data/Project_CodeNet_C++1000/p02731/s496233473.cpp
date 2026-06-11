#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    cin>>n;
    double a=n/3;
    int b=n/3;
    int c=n-2*b;
    if((a*a*a)>(b*b*c))
        cout<<fixed<<setprecision(8)<<a*a*a<<endl;
    else
        cout<<(b*b*c)<<endl;
}
