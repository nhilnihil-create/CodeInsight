#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    ft
    int t,i,j,n,m,l,r,x;
    string s;
    map<int,int>mp;
    cin>>s;
    reverse(s.begin(),s.end());
    l=r=0;
    x=1;
    mp[0]=1;
    for(char c:s)
    {
        r=((c-48)*x+r)%2019;
        l+=mp[r];
        mp[r]++;
        x=(x*10)%2019;
    }
    cout<<l<<"\n";
    return 0;
}