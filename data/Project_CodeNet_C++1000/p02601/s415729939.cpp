#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a,b,c,k;
    cin>>a>>b>>c>>k;
    if(b<=a)
    {
        while(k--)
        {
            b*=2;
            if(b>a)break;
        }
    }
    if(c<=b)
    {
        while(k--)
        {
            c*=2;
            if(c>b)break;
        }
    }
    if(a<b&&b<c)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
