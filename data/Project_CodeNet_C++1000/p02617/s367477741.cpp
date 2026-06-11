#include <iostream>
#include <cstdio>
#include <map>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <queue>
#include <ctime>
#include <utility> // std::pair
#include <functional> // std::greater <int> ()
#define int long long
#define MAXN 500000 // check
#define inf 1000000000000000001
#define BASE 29 // hashings mod, can be rand'd
#define mod 998244353 // can be 1000000007
#define pi 3.1415926535897
#define pii pair <int, int>
#define fii first
#define see second

typedef long long ll;
typedef long double ld;
using namespace std;

int n;
int ans=0;

// functions
void input(){
	cin >> n;
	for(int i=1; i<=n; i++) ans+=i*(n-i+1);
	int u, v;
	for(int i=1; i<n; i++)
	{
		cin >> u >> v;
		if(u>v)
		{
			int tmp=u;
			u=v;
			v=tmp;
		}
		ans-=u*(n-v+1);
	}
	return;
}

void solve(){
	cout << ans;
	return;
}

void output(){
	return;
}

signed main(){
/*
//  REMEMBER TO TURN OFF IFDEF IN PROBLEMS WITH FILE I/O
*/
//#ifdef sheeep
//	freopen("forces.inp", "r", stdin);
//	freopen("forces.out", "w", stdout);
//#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	int t;
//	cin >> t;
//	for(int i=1; i<=t; i++){
		input();
		solve();
		output();
//	}
	return 0;
}
// Author: NamSPro