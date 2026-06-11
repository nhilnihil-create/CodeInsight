#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long

using namespace std;

vector<int> e;

inline int solve(vector<int> &arr) {
	int ans = 0;
	int n = (int)arr.size();
	for(int i = 0; i < n; i++) {
		if(e[n - 1] == e[n - i - 1] + e[i]) {
			ans = (ans + arr[i]) % 2;
		}
	}
	return ans;
}

int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str; cin >> n >> str;
    vector<int> arr(n);
    for(i = 0; i < n; i++) {
    	arr[i] = str[i] - '1';
    }
    e.resize(n);
    for(i = 1; i < n; i++) {
    	e[i] = e[i - 1];
    	int cur = i, cnt = 0;
    	while(cur % 2 == 0) {
    		cur /= 2;
    		cnt++;
    	}
    	e[i] += cnt;
    }

    if(solve(arr) == 1) {
    	cout << 1;
    	return 0;
    }
    for(i = 0; i < n; i++) {
    	if(arr[i] == 1) {
    		cout << 0;
    		return 0;
    	}
    }
    for(i = 0; i < n; i++) {
    	arr[i] /= 2;
    }
    cout << 2 * solve(arr);

    return 0;
}
