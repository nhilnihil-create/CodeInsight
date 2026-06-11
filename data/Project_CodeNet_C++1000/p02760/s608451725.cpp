#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

ll mod = 1e9+7;

string solve() {
    int arr[3][3];
    int a;
    rep(i, 9) {
        cin >> a;
        arr[i/3][i % 3] = a;
    }
    int n; cin >> n;
    unordered_set<int> nums;
    rep(i, n) {
        cin >> a;
        nums.insert(a);
    }

    int rows = 0, cols = 0, diags = 0, anti_diags = 0;
    rep(i, 3) {
        if (nums.count(arr[i][i])) {
            diags++;
        }
        if (nums.count(arr[i][3 - i - 1])) {
            anti_diags++;
        }
        int cnt = 0;
        rep (j, 3) {
            if (nums.count(arr[i][j])) {
                cnt++;
            }
        }
        rows = max(rows, cnt);
    }

    rep(j, 3) {
        int cnt = 0;
        rep(i, 3) {
            if (nums.count(arr[i][j])) {
                cnt++;
            }
        }
        cols = max(cols, cnt);
    }

    if (rows == 3 || cols == 3 || diags == 3 || anti_diags == 3) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
