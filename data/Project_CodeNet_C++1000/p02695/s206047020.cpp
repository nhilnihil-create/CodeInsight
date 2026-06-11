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

#define br printf("\n")
#define pi acos(-1)

int N, M, Q;
vector<int> a, b, c, d;
 
int score(vector<int> A) {
    int res = 0;
    for (int i = 0; i < Q; i++) {
		if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
	}
    return res;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    for (int i = 0; i < Q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }
    queue<vector<int>> que;
    for (int i = 0; i < M; i++){
        vector<int> q = {i+1};
        que.push(q);
    }
    int ans = 0;
    while (!que.empty()){
        vector<int> elem = que.front();
        que.pop();
        if (elem.size()==N) ans = max(ans, score(elem));
        else {
			for (int i = (int)elem[elem.size()-1]; i < M + 1; i++) {
                vector<int> elem_new = elem;
                elem_new.push_back(i);
                que.push(elem_new);
            }
        }
    }
    cout << ans << endl;
	return 0;
}