#include <stdio.h>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;
typedef string STR;
typedef long long LL;

// variables()
/*int N, min_r = 1000001, max_c = -1000001, mn = 1000001, mx = -1000001;
pair <int, int> pr;
vector <pair <int, int> > vc;*/
///int plank, T, n, l, r, ans, sq, rct;
///STR op;
///vector <int> vc;
long A, B, N, mx = -1;
// variables(NULL)

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);
    srand(time(0));
    /// start_main()
	/*cin >> N;
	int grid[N][N];
	for (int i = 0 ; i < N ; i ++) {
        for (int j = 0 ; j < N ; j ++) {
            cin >> grid[i][j];
        }
	}
	for (int i = 0 ; i < N ; i ++) {
        for (int j = 0 ; j < N ; j ++) {
            min_r = min(min_r, grid[i][j]);
            max_c = max(max_c, grid[j][i]);
        }
        pr.first = min_r;
        pr.second = max_c;
        vc.push_back(pr);
        min_r = 1000001;
        max_c = -1000001;
	}
	for (int i = 0 ; i < N ; i ++) {
        mx = max(mx, vc[i].first);
        mn = min(mn, vc[i].second);
	}
	if (mx == mn) cout << 0;
	else {
        if (mx < mn) cout << 1;
        else cout << 2;
        multiset
	}
	cin >> plank;
	int arr[plank];
	for (int i = 0 ; i < plank ; i ++) {
        cin >> n;
        vc.push_back(n);
	}
	sort (vc.begin(), vc.end());
	r = vc.size() - 1;
	while (T --) {
        cin >> op >> n;
        if (op == '+') {
            vc.push_back(n);
            sort (vc.begin(), vc.end());
        }
        else {
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (vc[m] == n) {
                    ans = m;
                    break;
                }
                if (vc[m] < n) l = m + 1;
                else r = m - 1;
            }
            vc.pop(m);
        }
        for (int i = 0 ; i < vc.size() ; i ++) {
            for (int j = i + 1 ; j < vc.size() ; j ++) {
                if (vc[i] == vc[j]) {

                }
            }
        }
	}*/
    cin >> A >> B >> N;
    if (N < B) cout << floor(A * N / B) - A * floor(N / B);
    else cout << floor(A * (B - 1) / B) - A * floor((B - 1) / B);
    /// end_main()
    return 0;
}
