#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long LL;
const int MAXN = 2e6+10;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
signed main(){
	int m1,m2,d1,d2; cin>>m1>>d1>>m2>>d2;
	if(d1==a[m1]) puts("1"); else puts("0");
    return 0;
}
