#include<iostream>
using namespace std;
int main()
{
    long long n,m,mn,i,a,s=1;
    cin>>n;
    cin>>a;
    mn=a;
    for(i=2;i<=n;i++)
    {
        cin>>a;
        if(a<mn)
        {
            s++;
        }
        mn=min(mn,a);
    }
    cout<<s<<endl;  
    return 0;
}