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

signed main(){
	ios_base::sync_with_stdio(0);
	int n,r;
	cin>>n>>r;
	if(n>=10){
		cout<<r;
		re 0;
	}
	int a=100*(10-n);
	cout<<r+a;
	re 0;
}