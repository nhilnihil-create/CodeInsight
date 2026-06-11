#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
#define LL long long
LL n, ans;
map<LL,bool>mp;

bool check(LL y){
	LL x = n;
	while(x > 1){
		if(x % y == 0) x /= y;
		else{
			x %= y;
			break;
		}
		
	}
	if(x == 1) return 1;
	return 0;
}

int main(){ 
	cin>>n;
	for(LL i = 1; i * i <= n-1; i++) if((n - 1) % i == 0) ans += 2, mp[i] = mp[(n-1)/i] = 1;
	if( (LL)sqrt(n-1) * (LL)sqrt(n-1) == n - 1) ans--;
	for(LL i = 2; i * i <= n; i++) if(check(i) && mp[i] == 0) ans++;
	cout<<ans;
}