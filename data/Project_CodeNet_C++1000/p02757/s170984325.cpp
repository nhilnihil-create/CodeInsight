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
 
#define LL unsigned long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,P;
string S;

LL ans = 0;

void solve(){
	reverse(S.begin(),S.end());
	if(P==2 || P==5){
		for(int i=0;i<N;i++){
			LL num = S[i] - '0';
			if(num%P==0) ans += (N-i);
		}
		return;
	}

	vector<LL> pow10(200001,1);
	for(int i=1;i<=200000;i++) pow10[i] = (pow10[i-1]*10LL)%P;

	//1桁目からi桁目までを1つの数値とみなした時
	//それをPで割ったあまりをsub[i]とする
	//ただしsub[0]=0ときめる
	vector<LL> sub(N+1,0);
	for(int i=0;i<N;i++){
		LL num = S[i] - '0';
		sub[i+1] = (sub[i]+(num*pow10[i])%P)%P;
	}

	//subのうち、Pで割ったあまりがiのものの数を
	//classfied_by_mod[i]とする
	vector<LL> classfied_by_mod(P,0);
	for(int i=0;i<=N;i++){
		classfied_by_mod[sub[i]]++;
	}

	for(int i=0;i<P;i++){
		ans += (classfied_by_mod[i]-1)*classfied_by_mod[i]/2;
	}
}

int main(){
    cin >> N >> P;
    cin >> S;

    solve();

    cout << ans << endl;
    return 0;
}