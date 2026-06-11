//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc031/tasks/agc031_b

//参考：
//https://www.hamayanhamayan.com/entry/2019/03/17/003754

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
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
LL X[50],Y[50];

LL ans = 1;

void solve(){
	if(N==1) return;

	map<pair<LL,LL>,LL> counter;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			counter[pair<LL,LL>(X[i]-X[j],Y[i]-Y[j])]++;
			counter[pair<LL,LL>(-X[i]+X[j],-Y[i]+Y[j])]++;
		}
	}

	LL counter_max = 0;
	for(auto iter=counter.begin();iter!=counter.end();iter++){
		//cout << (iter->first).first << "," << (iter->first).second << "=" << iter->second << endl;
		counter_max = max(counter_max,iter->second);
	}
	ans = N - counter_max;
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> X[i] >> Y[i];
 
    solve();

    cout << ans << endl;
    return 0;
}