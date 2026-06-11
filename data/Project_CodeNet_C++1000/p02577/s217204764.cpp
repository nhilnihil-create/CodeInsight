/*
	LINES :
		* multiple of 9
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


#define pb push_back
#define F first
#define S second
#define WLL(t) while(t--)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define STF(i, a, b) for(size_t i = a; i < b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define SRF(i, a, b) for(size_t i = a;i >= b;i--)
#define ALL(v) v.begin(),v.end()
#define PRECISION(x) cout<<fixed<<setprecision(x)
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define MOD 1000000007

#define TO(v, type) static_cast<type>(v)

int main() {
#ifdef OJ
	READ;
	WRITE;
#endif
	string num;
	cin >> num;
	int sum{};
	FOR(i, 0, num.size()) {
		sum += num[i] - '0';
	}
	if (sum % 9 == 0)
	{
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}

}