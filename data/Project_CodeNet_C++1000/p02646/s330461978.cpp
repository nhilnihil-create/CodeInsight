//tokyokaijyo2020_b.cpp
//Sat Jul 11 10:15:25 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll a,v,b,w,t;
	cin >> a >> v >> b >> w >> t;

	if (w>=v){
		cout << "NO" << endl;
	}else if ((v-w)*t>=abs(b-a)){
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
}