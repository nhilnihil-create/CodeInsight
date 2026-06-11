#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int N;
	string S;
	cin >> N >> S;
	rep(i, S.size()){
		char a = S[i] + N;
		if (a - 'A' >= 26) a -= 26;
		cout << a; 
	}
	cout << endl;
	//cout << ans << endl;
	return 0;
}
