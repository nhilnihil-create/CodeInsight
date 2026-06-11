#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    if(b==1)
    {
        cout<<0<<'\n';
        return 0;
    }
    int now=1;
    for(int i=1;;i++)
    {
        now--;
        now+=a;
        if(now>=b)
        {
            cout<<i<<"\n";
            return 0;
        }
    }    
}