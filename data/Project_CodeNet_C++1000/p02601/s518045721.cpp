#include<iostream>
using namespace std;
int main()
{
    int a,b,c,k;
    cin>>a>>b>>c;
    cin>>k;
    while(k&&b<=a)
    {
        b=b*2;
        k--;
    }
    while(k&&c<=b)
    {
        c=c*2;
        k--;
    }
    
    if(a<b&&b<c)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}