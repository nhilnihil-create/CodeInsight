//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc165/tasks/abc165_e

//参考；
//https://www.youtube.com/watch?v=C5_NnCp1CRI&feature=youtu.be

//円形に1~Nを配置し、ペアを線で結んで作っていく考え方

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

LL N,M;

vector<pair<LL,LL>> ans;

void solve(){
	if(N%2==1){
		for(int i=1;i<=M;i++){
			ans.push_back(pair<LL,LL>(i+1,N-i+1));
		}
	}else{
		for(int i=1;i<=M;i++){
			if(N-i*2>N/2) ans.push_back(pair<LL,LL>(i+1,N-i+1));
			else ans.push_back(pair<LL,LL>(i+1,N-i));
		}
	}
}

int main(){
    cin >> N >> M;

    solve();

	for(int i=0;i<ans.size();i++)cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}