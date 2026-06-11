#include<bits/stdc++.h>
#define Abra_Ka_Dabra ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const long long mod = 1e9 + 7;
const double PI = acos(-1);
const double EPS = 1e-9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	Abra_Ka_Dabra

	string x;
	cin>>x;
	int ans;
	if(x=="RRR") ans=3;
	else if(x=="RRS"||x=="SRR") ans=2;
	else if(find(x.begin(), x.end(), 'R')!=x.end()) ans=1;
	else ans = 0;
	cout<<ans<<"\n";

	return 0;
}
