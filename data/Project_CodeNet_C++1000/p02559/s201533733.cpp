#include <iostream>
#include <algorithm>
#include <atcoder/all>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define PI 3.14159265359
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pai;
typedef pair<ll, ll> pal;
const int MOD = 1e9+7;
const ll LLINF = 1e18;


int main(){
	int n, q;
	cin >> n >> q;
	fenwick_tree<ll> fw(n);
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		fw.add(i, a);
	}

	for (int i = 0; i < q; i++){
		int ver;
		cin >> ver;
		if (ver == 0){
			int p, x;
			cin >> p >> x;
			fw.add(p, x);
		}else{
			int l, r;
			cin >> l >> r;
			cout << fw.sum(l, r) << endl;
		}
	}
	return 0;
}

