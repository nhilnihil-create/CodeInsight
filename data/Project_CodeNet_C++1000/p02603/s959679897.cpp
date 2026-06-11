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

LL N,M;
LL A[80];

LL ans = 0;

void solve(){
	LL money = 1000;
	for(int i=0;i<=N-2;i++){
		if(A[i]<A[i+1]){
			money = money/A[i]*A[i+1] + money%A[i];
		}
	}
	ans = money;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

    cout << ans << endl;
    return 0;
}