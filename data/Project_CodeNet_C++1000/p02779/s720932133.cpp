#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<long long,long long>m;
    long long n,i,x,f=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        m[x]++;
        if(m[x]>1)
        {
            f++;
        }
    }
    if(f>0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    return 0;
}