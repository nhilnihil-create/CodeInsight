#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b;
    cin>>a>>b;
    bool chex=false;
    for(float i=0;i<=1000000;i++)
    {
        int k=i*(0.08);
        int k1=i*(0.1);
        if(k==a && k1==b)
        {
            chex=true;
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}