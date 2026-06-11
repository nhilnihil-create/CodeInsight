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
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,K;
vector<vector<LL>> adj;//隣接行列
 
LL ans = 0;

void solve(){
	vector<LL> fact(N+1,1);//iの階乗をfact[i]とおく
	for(int i=2;i<=N;i++) fact[i] = (fact[i-1]*i)%mod_int;
	//BFS
	queue<LL> q;
	q.push(1);
	vector<LL> used(N+1,-1);//点Nにおいて、使用可能な色の数
	used[1] = K;
	ans = K;
	while(!q.empty()){
		LL now = q.front();q.pop();
		LL numof_branch = adj[now].size();//nowから伸びる枝の数
		LL counter = K-1;//使用可な色の数
		if(now!=1) counter--;
		for(LL next : adj[now]){
			if(used[next]==-1){
				used[next] = counter%mod_int;
				counter--;
				ans = (ans*used[next])%mod_int;
				q.push(next);
			}
		}
	}
}

int main(){
    cin >> N >> K;
    adj = vector<vector<LL>>(N+1);
    for(int i=0;i<N-1;i++){
    	LL a,b;cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
 
    solve();
 
    cout << ans << endl;
    return 0;
}