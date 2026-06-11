#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t;
    string s;
    set<char> se;
    cin>>s;
    for(i=0;i<s.size();i++) se.insert(s[i]);
    if(se.size()==2) cout<<"Yes";
    else cout<<"No";
}