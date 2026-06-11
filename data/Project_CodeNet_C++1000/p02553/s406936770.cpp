#include<iostream>
using namespace std;
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    cout<<max(a*c,max(b*d,max(a*d,b*c)));
}
