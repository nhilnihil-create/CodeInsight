/*
(͡ ° ͜ʖ ͡ °): Hi, be careful of overflow.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define v(x) vector<x>
#define pb push_back 
#define mp make_pair
#define maxint 1e18
#define mint -1e18

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i:a)cin>>i;
	int mx = 0;
	ll res = 0;
	for(int i=0;i<n;i++){
		if(a[i]< mx){
			res += mx - a[i];
		}else mx = max(mx,a[i]);
	}
	cout<<res<<'\n';
	return 0;
}