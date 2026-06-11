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
	int n;
	string s;
	cin>>n>>s;
	if(n%2){
		cout<<"No";
		re 0;
	}
	int x=n/2;
	if(s.substr(0,x)==s.substr(x)) cout<<"Yes";
	else cout<<"No";
	re 0;
}