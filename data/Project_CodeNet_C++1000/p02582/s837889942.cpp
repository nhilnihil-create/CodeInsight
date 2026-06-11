//bayemirov
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

#define pb push_back

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
   string s;
   cin >> s;
   int n = s.size(), k = 0;
   vector<int> block(n, 0);
   for (int i = 0; i < n; i++) {
   	if (s[i] == 'S') continue;
   	if (i > 0 && s[i - 1] != s[i]) ++k;
   	block[k]++;
   }
   cout << *max_element(block.begin(), block.end());
   return 0;
}