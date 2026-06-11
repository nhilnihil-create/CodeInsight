#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(auto x:s) 
    {
        cnt+=(x=='R');
    }    
    int ans=0;
    for(int i=0;i<cnt;i++)
    {
        ans+=(s[i]=='R');
    }
    cout<<cnt-ans;
    return 0;
}