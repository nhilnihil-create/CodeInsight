#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,m;
    cin>>n;
    string s;
    cin>>s;
    ll count=0;
    for(i=1;i<n;i++) if(s[i]!=s[i-1]) count++;
    cout<<count+1;
}