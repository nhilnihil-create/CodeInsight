#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4765
const int mod = 1000000007;
struct mint {
    ll x;
    mint(ll x=0):x(x%mod){}
    mint& operator+=(const mint a) {
	if ((x += a.x) >= mod) x -= mod;
	return *this;
    }
    mint& operator-=(const mint a) {
	if ((x += mod-a.x) >= mod) x -= mod;
	return *this;
    }
    mint& operator*=(const mint a) {
	(x *= a.x) %= mod;
	return *this;
    }
    mint operator+(const mint a) const {
	mint res(*this);
	return res+=a;
    }
    mint operator-(const mint a) const {
	mint res(*this);
	return res-=a;
    }
    mint operator*(const mint a) const {
	mint res(*this);
	return res*=a;
    }
};

mint c[4005][4005];
void init() {
    c[0][0] = 1;
    for (int i = 0; i <= 4000; i++) {
	for (int j = 0; j <= i; j++) {
	    c[i+1][j] += c[i][j];
	    c[i+1][j+1] += c[i][j];
	}
    }
}
mint comb(int n, int k) {
    return c[n][k];
}

int main(void){
    int n, k;
    cin >> n >> k;
    init();
    int all = n - k + 1;
    for(int i = 1; i <= k; i++){
	// mint ans = comb(all, i);
	if(n - i + 1 < i) std::cout << 0 << std::endl;
	else{
	    mint ans;
	    ans = comb(all, i);
	    ans *= comb(k-1, i-1);
	    cout << ans.x << endl;   
	} 
    }
    return 0;
}

