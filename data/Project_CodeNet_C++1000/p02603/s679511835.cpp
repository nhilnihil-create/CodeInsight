#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int a[100];
#define IOS ios::sync_with_stdio(0)
#define ull unsigned ll
#define uint unsigned
#define pai pair<int,int>
#define pal pair<ll,ll>
#define IT iterator
#define pb push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);++i)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);--i)
#define endl '\n'
#define ll long long
int main() {
	int n;cin>>n;
	int arr[n];
	for(int i = 0; i < n; ++i) cin>>arr[i];
	ll ans = 1e3;
	for(int i = 0; i < n - 1; ++i){
		ll st = 0;
		if(arr[i] < arr[i+1]) st = ans / arr[i];
		ans += (max(0, arr[i+1] - arr[i]))*st;
	}
	cout<<ans<<endl;
    return 0;
}
