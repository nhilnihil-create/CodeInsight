#include<bits/stdc++.h>

using namespace std;

#define forab(i,a,b) for(ll i = a; i < b; i++)
#define forn(n) for(ll i = 0; i < n; i++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define endl "\n"

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pi;

template<typename T>
void print(T nums) {
	for(auto& num: nums) {
		cout << num << " ";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL_PROJECT
	(void) freopen("input.txt", "r", stdin);
#endif
	double d, t, s;
	cin >> d >> t >> s;
	double T = d/s;
	if(T <= t) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}