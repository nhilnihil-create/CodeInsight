#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
#endif
	string s;
	cin >> s;
	int ans = 1, n = s.size();
	bool single = 1;
	for(int i = 1; i < n; i++){
		if(single){
			if(s[i] == s[i - 1]){
				if(i < n - 1)
					ans++, single = 0, i++;
				else
					break;
			}
			else
				ans++;
		}
		else
			ans++, single = 1;
	}
	cout << ans;
	return 0;
}
