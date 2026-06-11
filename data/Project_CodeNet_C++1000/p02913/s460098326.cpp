#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n;
string s;
int A[5050];
void Z_algo(string S){
	fill(A, A+5050, 0);
	A[0] = S.size();
	int i = 1, j = 0;
	while (i < S.size()) {
		while (i+j < S.size() && S[j] == S[i+j]) ++j;
		A[i] = j;
		if (j == 0) { ++i; continue;}
		int k = 1;
		while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
		i += k; j -= k;
	}
}
void solve(){
	cin >> n;
	cin >> s;
	
	int ma = 0;
	for(int i = 0; i < n; i++){
		Z_algo(s.substr(i));
		for(int j = 1; j < n-i; j++){
			chmax(ma, min(A[j],j));
		}
	}
	cout << ma << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
