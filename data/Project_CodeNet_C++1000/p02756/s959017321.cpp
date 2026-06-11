/*---Bismillahir Rahmanir Rahim---*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define mod 998244353
#define int long long
#define ld long double
#define pb push_back
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define vi vector <int> 
#define pii pair<int, int>
using namespace std; 

int  gcd(int a,int b){
	return  (b==0)?a: gcd(b,a%b);
}

inline void solve() {
	string s,h[2];
	int  f=0, n, q, ans=0 ; 
	cin >> s >> q ; 
	while (q--){
		cin>>n;
		if (n==2){
			int a; char c;
			cin >> a >> c ; 
			if (a==1) h[f] += c; 
			else h[!f] += c; 
		}
		else f = f^1;
	}
	string res;
	if (f&1) {
		reverse(h[1].begin(),h[1].end());
		reverse(s.begin(),s.end());
		res = h[1]; res += s; res += h[0];
	}
	else{
		reverse(h[0].begin(),h[0].end()); 
		res = h[0]; res += s; res += h[1];
	}
	cout << res << endl;
} 

signed main()
{
	int n = 1;
//	cin >> n;
	while (n--)
		solve();
	return 0;
}

/*
a
4
2 1 p
1
2 2 c
1

*/
