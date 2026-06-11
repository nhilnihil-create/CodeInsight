//
//	Created by shamim_nik
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,
		tree_order_statistics_node_update> indexed_set;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int N, M;
    cin >> N >> M;
    vector<int> H(N);
    vector<int> B(N, 1);
    for (int i = 0; i < N; i++) {
        cin >> H.at(i);
    }
    int a, b;
    while (cin >> a >> b) {
        a--, b--;
        if (H.at(a) < H.at(b)) {
            B.at(a) = 0;
        }
        else if (H.at(a) > H.at(b)) {
            B.at(b) = 0;
        }
        else {
            B.at(a) = B.at(b) = 0;
        }
    }
    int cnt = 0;
    for (auto b : B) {
        cnt += b;
    }
    cout << cnt << "\n";
}