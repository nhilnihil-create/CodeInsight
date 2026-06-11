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

vector<pair<int, int> > ans;

void make_ans(int start, int level){
	if (level == 1 || level == 0){
		ans.push_back(make_pair(start+1, start+level+2));
		return;
	}
	ans.push_back(make_pair(start+1, start+level+2));
	make_ans(start+1, level-2);
	return;
}

int main(){
	int n, m;
	cin >> n >> m;
	make_ans(0, m-1);
	if (m > 1) make_ans(m+1, m-2);
	for (int i = 0; i < m; i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}