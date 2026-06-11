#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_I_O ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9+7 , INF = 1e9 ,  mx = 100005 ;
main()
{
    fast_I_O;
    int i,j,n,m,x,y,sum=0,p=0,l,k;
    string s,t;
    cin>>s>>t;
    for(i=0;i<s.length();i++)
    {
        if(s[i]!=t[i]) ++p;
    }
    cout<<p;
    return 0;
}