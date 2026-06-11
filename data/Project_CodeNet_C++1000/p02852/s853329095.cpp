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

int N,M;
string S;

vector<int> ans;
 
void solve(){
	//iマス目からNマスめに到達するのに必要な最小手数をdp[i]とおく
	vector<int> dp(N+1,INF_INT);
	dp[N] = 0;
	queue<int> q;
	q.push(0);
	for(int i=N-1;i>=0;i--){
		while(1){
			if(q.size()==0){
				ans = vector<int>(1,-1);
				return;
			}
			if(q.front()!=INF_INT && q.size()<=M) break;
			q.pop();
		}
		if(S[i]=='0') dp[i] = q.front()+1;
		q.push(dp[i]);
	}

	int x = 0;
	int rest = dp[0];
	while(x<N){
		rest--;
		int i=1;
		while(dp[x+i]!=rest) i++;
		ans.push_back(i);
		x += i;
	}
}
 
int main(){
    cin >> N >> M;
    cin >> S;
 
    solve();
 
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
    return 0;
}