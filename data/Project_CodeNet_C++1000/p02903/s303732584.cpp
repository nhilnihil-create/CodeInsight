//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc038/tasks/agc038_a

//参考：
//https://www.programming-pack.com/entry/2019/10/29/235159

//ポイント：
//自由に構成する問題でも、落ち着いて行と列で分けて考えるのが重要

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

LL H,W,A,B;

bool no_flag = true;
vector<vector<int>> ans;

void solve(){
	no_flag = false;
	ans = vector<vector<int>>(H,vector<int>(W,0));
	for(int h=0;h<B;h++){
		for(int w=0;w<A;w++){
			ans[h][w] = 1;
		}
	}
	for(int h=B;h<H;h++){
		for(int w=A;w<W;w++){
			ans[h][w] = 1;
		}
	}
}
 
int main(){
    cin >> H >> W >> A >> B;
 
    solve();

    if(no_flag){
    	cout << "No" << endl;
    }else{
    	for(int h=0;h<H;h++){
    		for(int w=0;w<W;w++){
    			cout << ans[h][w];
    		}
    		cout << endl;
    	}
    }
    return 0;
}