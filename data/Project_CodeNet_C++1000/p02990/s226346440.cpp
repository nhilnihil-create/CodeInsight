#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

const int max_n = 3000;
Int N,K;
Int fact[max_n];
Int invfact[max_n];
Int inv[max_n];

void init(void) {
    fact[0] = fact[1] = 1;
    inv[0] = inv[1] = 1;
    invfact[0] = invfact[1] = 1;

    for(Int i = 2;i <= N;i++) {
        fact[i] = i*fact[i-1]%MOD;
        inv[i] = MOD - (MOD/i)*inv[MOD%i] % MOD;
        invfact[i] = inv[i]*invfact[i-1]%MOD;
    }
}

Int comb(Int n, Int r) {
    if(n < 0 || n < r)
        return 0;

    return ((fact[n]*invfact[n-r]%MOD)*invfact[r])%MOD;
}

int main(void) {
    cin>>N>>K;

    init();

    for(Int i = 1;i <= K;i++) {
        cout<<comb(N-K+1,i)*comb(K-1,i-1)%MOD<<endl;
    }

    return 0;
}
