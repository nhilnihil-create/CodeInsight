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
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
LL u[200000],v[200000];

LL ans = 0;

void solve(){
	LL numof_point = ((N*(2*N+1)*(N+1))/6LL + N*(N+1)/2LL)/2LL;
	LL numof_edge = 0;
	for(int i=0;i<N-1;i++){
		numof_edge += min(u[i],v[i])*(N-max(u[i],v[i])+1LL);
	}
	ans = numof_point - numof_edge;
}

int main(){
    cin >> N;
    for(int i=0;i<N-1;i++) cin >> u[i] >> v[i];

    solve();

    cout << ans << endl;
    return 0;
}