#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define v(x) vector<x>
#define pb push_back 
#define mp make_pair
#define maxint 1e18
#define mint -1e18

int main(){
	string s;
	cin>>s;
	ll x = 0,n=s.size();
	for(int i=0;i<n;i++){
		x += (s[i]-'0');
	}
	cout<<(x%9==0 ? "Yes\n":"No\n")<<'\n';

	return 0;
}