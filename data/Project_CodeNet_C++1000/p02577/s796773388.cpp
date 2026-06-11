#include<bits/stdc++.h>
using namespace std;
#define    For(i,n) for(int i=0;i<n;i++)
#define    fors(i,s) for(int i=0;i<s.size();i++)
#define    forn(i,n) for(int i=1;i<=n;i++)
#define    nl     "\n"
#define    test   int t;cin>>t;for(int l=0;l<t;l++)
#define    End    return 0
#define    gt     greater<int>()
#define    ll     long long int

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    //test
    {
        int sm=0;
        string s;
        cin>>s;
        fors(i,s)
        {
            sm+=s[i]-'0';
        }
        if(sm%9==0)cout<<"Yes"<<nl;
        else cout<<"No"<<nl;
    }
}
