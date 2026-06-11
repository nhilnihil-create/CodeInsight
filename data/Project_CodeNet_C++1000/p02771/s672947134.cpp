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
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if((a[0]==a[1]&&a[0]!=a[2])||(a[2]==a[1]&&a[2]!=a[0])) cout<<"Yes";
	else cout<<"No";
	re 0;
}