#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;

	int ans = 0;
	for (int ii = 0; ii < 10; ++ii){
		for (int jj = 0; jj < 10; ++jj){
			for (int kk = 0; kk < 10; ++kk){
				vector <int> v;
				v.push_back(ii);
				v.push_back(jj);
				v.push_back(kk);
				int idx = 0;
				for (int ss = 0; ss < N; ++ss){
					int num = S[ss] - '0';
					if (v[idx]==num){
						idx++;
						if (idx==3){
							break;
						}
					}
				}
				if (idx==3){
					ans++;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
