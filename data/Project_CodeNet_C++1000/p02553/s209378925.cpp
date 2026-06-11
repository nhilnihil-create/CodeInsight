#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int a,b,c,d,e,f,g;
cin>>a>>b>>c>>d;
e=max(a*c,a*d);
    f=max(e,b*c);
    g=max(f,b*d);
    cout<<g<<endl;
    

    return 0;}