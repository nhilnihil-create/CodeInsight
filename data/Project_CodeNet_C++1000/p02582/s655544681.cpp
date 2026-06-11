#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,t,b,c,d,l,r;
    string s;
    cin>>s;
    ll cnt=0,cnts=0;
    for(i=0; i<3; i++)
        if(s[i]=='R')
            cnt++;
        else
            cnts++;
    if(cnt==3)
        cout<<3<<'\n';
    else if(cnts==3)
        cout<<0<<'\n';
    else if(s[0]=='R' && s[1]=='R' || s[1]=='R' && s[2]=='R')
        cout<<2<<'\n';
    else
        cout<<1<<'\n';
}





