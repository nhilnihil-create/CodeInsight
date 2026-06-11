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

LL M;
LL D[200000],C[200000];

LL ans = 0;

void solve(){
	LL digit = 0;
	LL sum_per_digit = 0;
	for(int i=0;i<M;i++){
		sum_per_digit += (D[i]*C[i]);
		digit += C[i];
	}
	ans = (sum_per_digit)/9LL - (sum_per_digit%9LL==0) + digit - 1LL;
}

int main(){
    cin >> M;
    for(int i=0;i<M;i++){
    	cin >> D[i] >> C[i];
    }

    solve();

    cout << ans << endl;
    return 0;
}