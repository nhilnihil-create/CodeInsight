#include <iostream>
using namespace std;
const int MAX = 1000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	
 	COMinit();
	long long x,y;
  	cin >> x >> y;
  	if((2*x-y)%3 ==0 && (2*y-x)%3 == 0) {
    
    long long a = (2*x-y)/3;
    long long b = (2*y-x)/3;
      
    cout << COM(a+b, a) << endl;;
    
    
    
    } else {
    	cout << 0 << endl;
   }
}