//g++ -std=c++14 test.cpp -o test.out

 //全部開催すると仮定した後、1つずつ減らして調べていく

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

LL T1,T2;
LL A1,A2;
LL B1,B2;

LL ans = 0;

void solve(){
	if(A1<B1){
		swap(A1,B1);
		swap(A2,B2);
	}
	LL diff = (B1*T1+B2*T2) - (A1*T1+A2*T2);
	if(diff<0LL) ans = 0;
	if(diff==0LL) ans = -1;
	if(diff>0LL){
		LL diff_T2 = diff;
		LL diff_T1 = (A1 - B1)*T1;
		if(diff_T1%diff_T2==0LL){
			ans = (diff_T1/diff_T2)*2LL;
		}else{
			ans = diff_T1/diff_T2*2LL + 1LL;
		}
	}
}

int main(){
    cin >> T1 >> T2;
    cin >> A1 >> A2;
    cin >> B1 >> B2;

    solve();

    if(ans==-1){
    	cout << "infinity" << endl;
    	return 0;
    }
	cout << ans << endl;
    return 0;
}