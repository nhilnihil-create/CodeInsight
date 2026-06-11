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
    string s1,s2;
    cin>>s1>>s2;
    ll count=0;
    for(i=0;i<s1.size();i++) if(s1[i]==s2[i]) count++;
    cout<<count;
    
}