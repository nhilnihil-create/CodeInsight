#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
int main()
{
    IOS;
    //freopen("inputfile.txt","r",stdin);
    int x,y;cin>>x>>y;
    for(int i=0;i<=x/2;i++)
    {
        int l = x-i;
        if((l*2+i*4)==y)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        else if((i*2+l*4)==y)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
