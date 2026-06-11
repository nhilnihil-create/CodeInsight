#include"bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forr(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
double PI = 3.14159265;
using namespace std;
using Graph = vector<vector<int>>;
using Field = vector<string>;
using DGraph = vector<vector<pair<int, int>>>;

const long long INF = 1LL << 60;
//---//
int main() {
	ll A, B,a,b ,N; cin >> N >> a >> b;
	if (a < b) {
		A = b;
		B = a;
	}
	else {
		A = a;
		B = b;
	}

	if ((A - B) % 2 == 0)cout << (A - B) / 2 << endl;
	else cout << min((2*N-A-B+1)/2,(A-1+B)/2) << endl;

	return 0;
}
