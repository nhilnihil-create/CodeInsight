#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    ll n,max=0; cin>>n; map<string,ll>m; string s;
    while(n--)
    {
        cin>>s; m[s]++;
        if (m[s]>max){max=m[s];}
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        if (it->second==max) {cout<<it->first<<endl;}
    }
	return 0;
}