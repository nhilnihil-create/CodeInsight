#include <bits/stdc++.h>
using namespace std;

#define F0R(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	FOR(i,1,5) {
		int x; cin >> x;
		if(x == 0) { 
			cout << i << "\n";
			return 0;
		}
	}
}
