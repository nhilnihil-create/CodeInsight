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

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	long long num , cnt = 0, sum = 100;
	cin >> num;
	while(sum < num) {
		cnt++;
		sum += sum / 100;
	}
	cout << cnt << endl;
	return 0;
}