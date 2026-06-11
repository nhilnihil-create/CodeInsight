#include <iostream>
#define MOD 1000000007
typedef long long LL;
using namespace std;

LL calc(LL x, LL n){
    LL ans = 1;
    while(n > 0){
        if(n & 1){
            ans = ans * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return ans;
}


int main(){
    LL x,n;

    cin >> x >> n;
    cout << calc(x,n) << endl;

}
