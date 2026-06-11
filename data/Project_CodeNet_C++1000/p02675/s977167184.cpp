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

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int N;
  	cin >> N;
	N %= 10;
	if (N == 3) {
		cout << "bon" << endl;
	} else if (N == 0 || N == 1 || N == 6 || N == 8) {
		cout << "pon" << endl;
	} else {
		cout << "hon" << endl;
	}
	return 0;
}