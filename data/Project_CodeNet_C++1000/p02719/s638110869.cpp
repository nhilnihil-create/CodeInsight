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
int n,k;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	int a=n%k,b=k-a;
	cout<<min(a,b);
	re 0;
}