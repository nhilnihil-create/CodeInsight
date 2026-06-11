#include<bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair
 
typedef long long ll;
typedef unsigned long long int ull;
typedef long double ld;
 
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
 
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, pii>> vpiii;
 
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<int, ll> mill;
typedef map<int, vi> mivi;
typedef map<int, vpii> mivpii;

set<int> S;

int n, x;

void fast_io() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	fast_io();
//	freopen("input/ABC154C.txt", "r", stdin);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		S.insert(x);
	}
	
	cout << (n == S.size() ? "YES" : "NO") << '\n';
	
	return 0;
}