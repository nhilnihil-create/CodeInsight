//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
//const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
LL A[100001];

LL ans = -1;

void solve(){
	if(N==0){
		if(A[0]==1) ans = 1;
		return;
	}
	//深さiの、それぞれ考えられるノードの数の
	//最小値と最大値
	vector<LL> min_node(N+1);
	vector<LL> max_node(N+1);
	min_node[N] = A[N];
	max_node[N] = A[N];
	for(int i=N-1;i>=0;i--){
		min_node[i] = max(1LL + A[i],(min_node[i+1]+1LL)/2LL + A[i]);
		max_node[i] = min(max_node[i+1] + A[i],INF);
		if(min_node[i]>max_node[i]) return;
	}

	// for(int i=0;i<=N;i++){
	// 	printf("depth=%d:[%lld,%lld]\n",i,min_node[i],max_node[i]);
	// }

	LL allof_nodes = 1;
	LL prev_nodes = 1;
	for(int i=1;i<=N;i++){
		LL enable_nodes = (prev_nodes-A[i-1])*2LL;
		LL used_nodes = min(max_node[i],enable_nodes);
		//printf("d=%d:%lld\n",i,used_nodes);
		if(used_nodes<min_node[i]) return;
		allof_nodes += used_nodes;
		prev_nodes = used_nodes;
	}
	ans = allof_nodes;
}

int main(){
    cin >> N;
    for(int i=0;i<=N;i++) cin >> A[i];

    solve();

    cout << ans << endl;
    return 0;
}