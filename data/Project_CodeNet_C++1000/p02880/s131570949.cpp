#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a,chk=0;
    cin>>n;
    for(i=1;i<10;i++)
    {
        if(n%i==0)
        {
            a=n/i;
            if(a>0 && a<10)
            {
                chk=1;
                break;
            }
        }
    }
    if(chk)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
