#include <bits/stdc++.h>
using namespace std;

template<typename T> T combination(int n, int r) {
    T ans = 1;
    for (int i = 0; i < r; i++) {
        ans *= n - i;
    }
    for (int i = 1; i <= r; i++) {
        ans /= i;
    }
    return ans;
}

int main() {
    int N;
    map<string, int> M;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        M[s]++;
    }
    long long ans = 0;
    for (auto it = M.begin(); it != M.end(); it++) {
        ans += combination<long long>((*it).second, 2);
    }
    cout << ans << endl;
	return 0;
}