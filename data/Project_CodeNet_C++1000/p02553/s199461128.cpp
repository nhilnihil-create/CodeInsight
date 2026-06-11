#pragma GCC optimize("-O2")
#include<bits/stdc++.h>
#define int long long
#define vi vector<int> 
#define pb push_back
#define eb emplace_back
#define For(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define MAX 100005
#define endl '\n'
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	// freopen("output1.txt", "w", stdout);
	#endif
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int res=INT_MIN;
	res = max(a*d*1LL,a*c*1LL);
	res = max(res,b*c*1LL);
	res= max(res,b*d*1LL);
	cout<<res<<endl;
}