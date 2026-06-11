#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
const int MOD = 1e9+7;
const int MOOD = 998244353;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int n, m, q, ans;
int a[50], b[50], c[50], d[50];

void dfs(vector<int> &vec){
	if (vec.size() == n){
		int temp_ans = 0;
		for (int i = 0; i < q; i++){
			if (vec[b[i]-1] - vec[a[i]-1] == c[i]){
				temp_ans += d[i];
			}
		}
		ans = max(ans, temp_ans);
		return;
	}
	if (vec.size() == 0){
		for (int i = 1; i <= m; i++){
			vec.push_back(i);
			dfs(vec);
			vec.pop_back();
		}
	}else{
		for (int i = vec[vec.size()-1]; i <= m; i++){
			vec.push_back(i);
			dfs(vec);
			vec.pop_back();
		}
	}
	return;
}

int main(){
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	vector<int> vec;
	dfs(vec);
	cout << ans << endl;
	return 0;
}