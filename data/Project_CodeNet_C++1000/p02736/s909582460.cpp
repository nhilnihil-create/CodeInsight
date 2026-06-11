#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;

LL n,m,tmp = 2,ans = 0;
LL a[2000005];
char ch;
map <LL,LL> mp;

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(LL i = 1;i <= n;i ++){
		cin >> ch;
		a[i] = ch - '0' - 1;
		if(a[i] == 1) tmp = 1;
	}
	if(tmp == 2){
		for(LL i = 1;i <= n;i ++){
			if(a[i] == 2) a[i] = 1;
		}
	}
	else{
		for(LL i = 1;i <= n;i ++){
			if(a[i] == 2) a[i] = 0;
		}
	}
	for(LL i = 1;i <= n;i ++) if(((n - 1) & (i - 1)) == i - 1) ans ^= a[i]; 
	cout << (ans ? tmp : 0) << endl;
	return 0;
}
//