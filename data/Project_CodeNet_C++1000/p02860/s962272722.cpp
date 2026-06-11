#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int N;
	string S;
	cin >> N >> S;
	int length = S.size();
	string ans = "Yes";
	if (length%2 != 0){
		ans = "No";
	}
	else{
		length /= 2;
		rep(i, length){
			if (S[i] != S[i + length]) ans = "No";
		}
	}
	cout << ans << endl;
	return 0;
}
