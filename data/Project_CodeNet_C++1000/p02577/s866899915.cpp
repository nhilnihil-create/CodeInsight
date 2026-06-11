#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define pf(n) cout << n << endl
#define ps() cout <<" ";
#define sf(n) cin >> n
#define in(i,n) for (int i = 0; i < n; i++)
#define mn -
#define pls +
#define mod %
#define E =
#define EE ==
#define le <=
#define ge >=
int mx=9999999;
/**  '' "\n" - ^ **/

inline void yes(int counter){
	if(counter EE 0)
    cout<<"yes\n";
    else if(counter EE 1)
    cout<<"Yes\n";
    else cout<<"YES\n";
    return;
}
inline void no(int counter){
	if(counter EE 0)
    cout<<"no\n";
    else if(counter EE 1)
    cout<<"No\n";
    else cout<<"NO\n";
    return;
}

inline int inc(int i,int j)
{
	return i + j;
}
inline int dec(int i,int j)
{
	return i - j;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin>>a;
    int sum E 0;
    in(i,a.length())
    {
    	sum E inc(sum,a[i] mn 48);
	}
	if(sum mod 9 EE 0)
	{
		yes(1);
	}
	else
	{
		no(1);
	}
}
