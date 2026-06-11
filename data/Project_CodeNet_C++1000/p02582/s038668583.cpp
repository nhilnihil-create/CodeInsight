#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_I_O ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9+7 , INF = 1e9 ,  mx = 100005 ;
main()
{
    fast_I_O;
    int i,j,n,m,x=0,y,sum=0,p=0,l,k;
    string s;
    cin>>s;
    for(i=0;i<3;i++)
    {
        if(s[i]=='R')
        ++p , x=max(x,p);
        else p=0;
    }
    cout<<x;
    return 0;
}