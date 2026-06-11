#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define SP << " " 
#define LLi long long int

using namespace std;

LLi mod=1000000007;

void PV(vector<int> pvv) {
	rep(i, pvv.size()) cout << pvv[i] SP;
	cout << endl;
}
 
LLi modinv(LLi a) {
    LLi b = mod, u = 1, v = 0;
    while (b) {
        LLi t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}
 
LLi modpow(LLi a, LLi n) {
    LLi res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

//xCyを計算
LLi conb(LLi x, LLi y){
	if(x<y) cout<< "conb x<y" << x SP << y <<endl;
	LLi tmp=1;
	//y=min(y, x-y); 8C2==8C6なので
	
	for(int i=1;i<=y;i++){
		tmp*=x+1-i;
		tmp=tmp%mod;
		tmp*=modinv(i);
		tmp=tmp%mod;
	}

	return tmp;
}

//xPyを計算
LLi perm(LLi x, LLi y){
	if(x<y) cout<< "conb x<y" << x SP << y <<endl;
	LLi tmp=1;
	
	for(int i=1;i<=y;i++){
		tmp*=x+1-i;
		tmp=tmp%mod;
	}

	return tmp;
}

int main(){

	long long int n, a, b;
	LLi tmp, ans=0;
	cin>> n >> a >> b;

	ans+=modpow(2, n)-1;
	ans=ans%mod;
	ans+=mod-conb(n, a);
	ans=ans%mod;
	ans+=mod-conb(n, b);
	ans=ans%mod;
  
  cout<< ans <<endl;

	return 0;
}