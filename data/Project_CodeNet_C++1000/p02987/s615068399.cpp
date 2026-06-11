#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
int main()
{
    ft
    ll t,i,j,n,m,l,r;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s[0]==s[1] && s[2]==s[3] && s[1]!=s[2])
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}