#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,k,l;
    cin>>a>>b>>c>>d;
    k=a/d;
    if(a%d!=0)
    {
        k++;
    }
    l=c/b;
    if(c%b!=0)
    {
        l++;
    }
    if(l<=k)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}