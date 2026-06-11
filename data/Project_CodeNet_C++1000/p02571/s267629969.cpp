#include<bits/stdc++.h>

#define LL long long
#define MOD 1000000007
#define rep(i,n) for(int i = 0;i < (n);i++)

using namespace std;

LL gcd(LL C, LL D) {
	if (C < D) gcd(D, C);

	if (C%D == 0)return D;
	else gcd(D, C%D);
}



int main() {
	string s, t;
	int ans = 0;

	cin >> s >> t;
	for (int i = 0; i < s.length()-t.length()+1; i++) {
		int cnt = 0;
		rep(j, t.length()) {
			if (s[i+j] == t[j]) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}

	cout<< t.length()-ans << endl;
  return 0;
}




