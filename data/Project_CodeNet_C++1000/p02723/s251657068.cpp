#include<bits/stdc++.h>
using namespace std;
#define int     long long
#define F       first
#define S       second
#define _READ   freopen("input.txt","r", stdin);
#define _FAST   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
void solve()
{
	string s;
	cin>>s;
	if(s[2]==s[3] && s[5]==s[4])
		cout<<"Yes";
	else
		cout<<"No";
}
int32_t main()
{
    
    int t;
    t=1;
    while(t--)
        solve();
    return 0;
}
/*
===FOR N-Dimensional Vector===
https://codeforces.com/blog/entry/76149
g++ -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined a.cpp -o a -D_GLIBCXX_DEBUG
*/