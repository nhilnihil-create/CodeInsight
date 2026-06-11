//g++ -std=c++14 test.cpp -o test.out

//ポイント：
//いもす法
//操作をシミュレートすると、高々lon(N)回程度で数列が収束することに気付けるか
//数列は合計値、下限、上限に注目

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

LL N,K;
LL A[200000];

LL ans[200000];

void solve(){
	auto sanitizer = [&](LL x){
		if(x<0) x = 0;
		if(x>N) x = N;
		return x;
	};
	for(int _=0;_<K;_++){
		//いもす法
		vector<LL> d_imos(N+1,0);
		for(int i=0;i<N;i++){
			d_imos[sanitizer(i-A[i])]++;
			d_imos[sanitizer(i+A[i]+1)]--;
		}
		vector<LL> imos(N,1);//電球は少なくとも自分自身を照らしている　よってデフォで1としておく
		imos[0] = d_imos[0];
		for(int i=1;i<N;i++) imos[i] = imos[i-1] + d_imos[i];

		LL sum = 0;
		for(int i=0;i<N;i++){
			A[i] = imos[i];
			sum += imos[i];
		}
		if(sum==N*N) break;
	}

	for(int i=0;i<N;i++) ans[i] = A[i];
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

    for(int i=0;i<N;i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}