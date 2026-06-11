#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll n,m,t,i,j,a,b,k;
    string s;
    cin>>n>>s;
    for(i=0;i<s.size();i++)
    {
        for(j=0;j<n;j++)
        {
            s[i]++;
            if(s[i]=='Z'+1) s[i]='A';
        }
    }
    cout<<s;
    
}