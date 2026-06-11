#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int n;
set<int> st;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		st.insert(a);
	}
	cout<<(sz(st)==n?"YES":"NO");
	re 0;
}