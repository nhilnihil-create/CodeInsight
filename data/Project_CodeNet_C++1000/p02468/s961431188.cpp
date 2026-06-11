#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

/////

const i64 mod = (i64)1e9+7;

i64 power(i64 e, i64 x){
    if(x == 0)return 1LL;
    i64 p = power(e, x/2);
    if(x&1)return p * p % mod * e % mod;
    else return p * p % mod;
}

int main(){
    i64 e,x;
    cin >> e >> x;
    cout << power(e,x) << endl;
}
