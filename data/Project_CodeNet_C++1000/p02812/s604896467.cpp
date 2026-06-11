#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main()
{
    ll n,m,i,a,b,k,t;
    string s;
    cin>>n>>s;
    string abc="ABC";
    ll count=0;
    for(i=0;i<s.size()-3+1;i++)
    {
        string temp=s.substr(i,3);
        if(temp==abc) count++;
    }
    cout<<count;
}