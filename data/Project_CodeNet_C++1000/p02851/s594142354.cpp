#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long LL;

LL n,k,a[200005];
LL pre[200005] = {0};
map <LL,LL> mp;
LL tot = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(LL i = 1;i <= n;i ++){
		cin >> a[i]; a[i] --; a[i] %= k;
		pre[i] = pre[i - 1] + a[i]; pre[i] %= k;
    }
	mp[pre[0]] = 1;
	for(LL i = 1;i <= n;i ++){
		if(i >= k) mp[pre[i - k]] --; 
		tot += mp[pre[i]]; 
		mp[pre[i]] ++; 
	}
	cout << tot << endl;
	return 0;
}