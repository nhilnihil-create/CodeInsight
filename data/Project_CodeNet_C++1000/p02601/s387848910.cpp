// AUTHOR: ROSHAN SRIVASTAVA
// WEBSITE: https://www.youtube.com/channel/UC6uQdd7kLLOdlHSVklhV7Cw

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int k, r, g, b; 

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin>>r>>g>>b;
	cin>>k;

	while(r >= g) {
		g *= 2;
		k--;
	}

	while(g >= b) {
		b *= 2;
		k--;
	}

	if(k < 0) cout<<"No\n";
	else cout<<"Yes\n";

	return 0;
}