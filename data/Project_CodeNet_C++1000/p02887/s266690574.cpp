#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main() {
    ll n,i; string s; cin>>n>>s;
    for(i=0;i<s.length()-1;i++)
    {
        if (s[i]==s[i+1]) {n--;}
    } cout<<n;
	return 0;
}