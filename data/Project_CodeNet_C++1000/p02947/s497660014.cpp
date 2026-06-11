#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<string, int> frq;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	sort(s.begin(), s.end());
    	ans += frq[s]++;
    }
    cout << ans << "\n";
    return 0;
}

