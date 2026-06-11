/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Practice Atcoder
*/

#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define int             long long
#define dip(type,var)   type var; cin>>var;
#define dipi(x)			int x; cin>>x;
#define w(x)            int x; cin>>x; while(x--)
#define mka(arr,n,type) type *arr=new type[n];
#define fo(i,n)			for(int i=0;i<n;i++)
#define mod             pow(10,9)+7
#define inf             1e18
#define pi 				3.141592653589793238
#define fo(i,n)        for(int i=0;i<n;i++)
#define endl			"\n"
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >

void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {
	c_p_c();
	dipi(n);
	dipi(m);
	mka(arr, m, int);
	int sum = 0;
	fo(i, m) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum <= n)
		cout << n - sum << endl;
	else
		cout << "-1" << endl;
}