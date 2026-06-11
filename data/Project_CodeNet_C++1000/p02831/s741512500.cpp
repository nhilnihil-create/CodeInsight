#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    long long a,b,p,q,i,l;
    cin>>a>>b;
    p=max(a,b);
    q=min(a,b);
    for(i=1;i>=1;i++)
    {
        l=p*i;
        if(l%q==0)
        {
            cout<<l<<endl;
            break;
        }
    }    
    return 0;
}