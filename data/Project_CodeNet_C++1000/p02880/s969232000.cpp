#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,f,i,rem;
    cin>>n;
    f=0;
    for(i=1;i<=9;i++)
    {
        if(n%i==0 && (n/i)<=9)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
