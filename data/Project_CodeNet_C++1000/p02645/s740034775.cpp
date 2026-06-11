#include<bits/stdc++.h>
using namespace std;
 
#define MOD 998244353
template<typename ty1,typename ty2>
inline int add(ty1 x, ty2 y) {
	if(y>=MOD)y%=MOD;
	if(x>=MOD)x%=MOD;
    x += y; return x < MOD ? x : x - MOD;
}
template<typename ty1,typename ty2>
inline void addto(ty1 &x, ty2 y) {
		  if(y>=MOD)y%=MOD;
		  if(x>=MOD)x%=MOD;
	      x += y; if (x >= MOD) x -= MOD;
}
template<typename ty1,typename ty2>
inline int sub(ty1 x, ty2 y) {
		if(y>=MOD)y%=MOD;
		 if(x>=MOD)x%=MOD;
        x -= y; return x < 0 ? x + MOD : x;
}
template<typename ty1,typename ty2>
inline void subto(ty1 &x, ty2 y) {
	if(y>=MOD)y%=MOD;
	if(x>=MOD)x%=MOD;
    x -= y; if (x < 0) x += MOD;
}
template<typename ty1,typename ty2>
inline int mul(ty1 x, ty2 y) {
        if(y>=MOD)y%=MOD;
		if(x>=MOD)x%=MOD;
        return 1ll * x * y % MOD;
}
template<typename ty1,typename ty2>
void multo(ty1 &x, ty2 y) {
        if(y>=MOD)y%=MOD;
		if(x>=MOD)x%=MOD;
        x=1ll * x * y % MOD;
}
  
long long int gcd(long long int a, long long int b){
	if (a > b){
		swap(a, b);
	}
	while (a){
		swap(a, b);
		a %= b;
	}
	return b;
}
long long int lcm(long long int a, long long int b){
	return a / gcd(a, b)*b;
}
long long int ppow(long long int i, long long int j){
		long long int res = 1LL;
		while (j){
			if ((j & 1LL)){
				res *= i;
				if (res >= MOD){
					res %= MOD;
				}
			}
			j >>= 1;
			i *= i;
			if (i >= MOD){
				i %= MOD;
			}
		}
		return res;
	}
class Combination{
	
public:
	vector<long long int> k;
	vector<long long int> r;
	void resize(int N){
		k.resize(N + 2);
		r.resize(N + 2);
		k[0] = 1;
		for (int i = 1; i < N+2; i++){
			k[i] = k[i - 1];
			k[i] *= i;
			if (k[i] >= MOD)k[i] %= MOD;
		}
		long long int al = k[k.size() - 1];
		long long int iv = ppow(k[k.size() - 1],MOD-2);
		r[k.size() - 1] = iv;
		for (int i = (int)(r.size()) - 2; i >= 0; i--){
			r[i] = r[i + 1] * (i + 1);
			if (r[i] >= MOD){
				r[i] %= MOD;
			}
		}
	}
	long long int C(int a, int b){
		if (a < b)return 0;
		long long int up = k[a];
		long long int dw = r[b] * r[a - b];
		dw %= MOD;
		up *= dw;
		up %= MOD;
		return up;
	}
	long long int H(int a, int b){
		return C(a + b - 1, b);
	}
	long long int catalan_number(int n){
		return (C(2 * n, n) + MOD - C(2 * n, n - 1)) % MOD;
	}
};
Combination C;

int main(){
	string s;
	cin>>s;
	cout<<s.substr(0,3)<<endl;
	return 0;
}
