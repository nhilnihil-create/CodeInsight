#include <bits/stdc++.h>
#define ll long long
#define pb push_back 
#define mp make_pair
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
map < char, int> p;
int main() { fastIO
	string s1;
	cin >> s1;
	int l = 0, r = 0;
	int ans = 0, piv = 0;
	for (char c : s1){
		if (c == 'R')++piv;
		else{
			ans = max(ans, piv);
			piv = 0;
		}
	} ans = max(ans, piv); 
	cout << ans << endl;

	    return 0;	
}

