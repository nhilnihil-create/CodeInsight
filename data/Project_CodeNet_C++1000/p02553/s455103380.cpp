
#include<bits/stdc++.h>
using namespace std;   
int main()
{
long long int  a,b,c,d;
    long long int x[5];
    cin>>a>>b>>c>>d;
    x[0]=a*c;
    x[1]=a*d;
    x[2]=b*c;
    x[3]=b*d;
    sort(x,x+4);
    cout<<x[3]<<endl;
}
