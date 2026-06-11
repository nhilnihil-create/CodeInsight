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
	freopen("output1.txt", "w", stdout);
	#endif
	string s,t;
	cin>>s>>t;
	int n=s.length(),m=t.length(),cnt=0;
	int mn=INT_MAX;
	if(n==m){
		for(int i=0;i<n;i++){
			if(s[i]!=t[i])cnt++;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=0;i<n-m;i++){
		cnt=0;
		for(int j=0;j<m;j++){
			if(s[i+j]!=t[j])cnt++;
		}
		mn=min(cnt,mn);
	}
	cout<<mn;
}