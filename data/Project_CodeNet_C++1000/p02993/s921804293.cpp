#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;
typedef pair<int, int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;

	rep(i,s.size()-1){
		if(s[i] == s[i+1]){
			cout << "Bad" << endl;
			return 0;
		}
	}
	cout << "Good" << endl;
	return 0;
}