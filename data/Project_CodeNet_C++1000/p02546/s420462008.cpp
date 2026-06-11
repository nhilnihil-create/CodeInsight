#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
const ll maxn=(3*1e3)+5;
const int N = 1e5;
int main()
{
    string s;
    cin>>s;
    ll l=s.length();
    if(s[l-1]=='s')
        cout<<s<<"es"<<"\n";
    else
        cout<<s<<"s"<<"\n";
    cerr<<"\nTime elapsed:"<< 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
