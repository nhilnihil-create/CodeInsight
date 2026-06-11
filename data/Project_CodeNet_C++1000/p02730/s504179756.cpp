#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string s,t1,t2;
    cin>>s;
    ll half=s.size()/2;
    t1=s.substr(0,half);
    t2=s.substr(half+1,s.size());
    string rev=t1;
    reverse(rev.begin(),rev.end());
    if(t1==rev && t1==t2) cout<<"Yes";
    else cout<<"No";
}