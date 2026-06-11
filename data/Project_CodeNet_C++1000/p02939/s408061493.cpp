#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	string s;
	cin >> s;
	int l = s.size();
	int cnt = 1;
	int i = 1;
	bool two = false;
	while (true)
	{
		if (i > l-1) break;
		if (s[i-1]!=s[i] || two) {
			cnt++;
			i++;
			two = false; continue;
		}
		else if (i != l-1){
			cnt++;
			i += 2;
			two = true; continue;
		}
		i++;
	}
	cout << cnt << endl;
	
	return 0;
}