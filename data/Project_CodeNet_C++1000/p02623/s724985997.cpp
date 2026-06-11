#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;

// Prefix Sum + Binary Search
int solve(vll A, vll B, int k) {
    int res = 0;
    for (size_t i = 1; i < A.size(); ++i) {
        A[i] += A[i - 1];
        if (A[i] <= k) {
            res = max(res, static_cast<int>(i + 1));
        }
    }
    for (size_t i = 1; i < B.size(); ++i) {
        B[i] += B[i - 1];
        if (B[i] <= k) {
            res = max(res, static_cast<int>(i + 1));
        }        
    }
    
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] > k) {
            break;
        }
        ll target = k - A[i];
        auto it_B = lower_bound(B.begin(), B.end(), k - A[i]);
        if (it_B - B.begin() >= static_cast<int>(B.size())) {
            continue;
        }
        int j = (*it_B == target) ? it_B - B.begin() : it_B - B.begin() - 1;
        if (j < static_cast<int>(B.size())) {
            res = max(res, static_cast<int>(i + j + 2));
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
    int a;
    vll A, B;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        cin >> a;
        B.push_back(a);
    }

    cout << solve(A, B, k) << endl;
}
