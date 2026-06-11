#include <bits/stdc++.h>
using namespace std;
#define forloop(n) for(int i = 0; i < n; i++)
#define ll long long

#define mod 998244353
long long exp(long long taban, long long us) {
    long long carpan = taban;
    long long temp = us;
    long long res = 1;
    for(int i = 0;;i++){
        if(temp % 2) res = (res*carpan) % mod;
        temp /= 2;
        carpan = (carpan*carpan) % mod;
        if(temp == 0) break;
    }
    return res;
}
int main(){
	int n; cin>>n;
	ll arr[100005] = {};
	int maks = 0;
	forloop(n){
		int sayi; cin>>sayi;
		if( (i == 0 && sayi != 0) || arr[0] > 1){
			cout<<0;
			return 0;
		}
		arr[sayi]++;
		maks = max(maks, sayi);
	}
	ll res = 1;
	for(int i = 1; i <= maks; i++){
		res = (res * exp(arr[i-1], arr[i])) % mod;
	}
	cout<<res;
	return 0;
}