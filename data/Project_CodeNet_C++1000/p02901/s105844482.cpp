#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> cost(1<<n,INF);

	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b;
		int idx = 0;
		for(int j = 0;j < b;j++){
			int c;
			cin >> c;
			c--;
			idx += (1 << c);
		}
		cost[idx] = min(cost[idx],a);
	}

	int sz = cost.size();
	for(int i = 0;i < sz-1;i++){
		for(int j = i+1;j < sz;j++){
			cost[i|j] = min(cost[i|j],cost[i]+cost[j]);
		}
	}

	if(cost[sz-1] == INF)cout << -1 << endl;
	else cout << cost[sz-1] << endl;
}
