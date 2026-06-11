//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin>>s;
    if(s[s.length() - 1] == 's')
        s += "es";
    else
        s += 's';
    
    cout<<s<<endl;
}