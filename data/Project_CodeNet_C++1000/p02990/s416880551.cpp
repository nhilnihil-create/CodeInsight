#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

#define MOD 1000000007
#define N 20000
long long fac[N],finv[N],inv[N];

void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2;i <= N;i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

long long COM(int n,int k)
{
    if (n < k || n < 0 || k < 0){
        return 0;
    }
    else if (k == 0 || n == k){
        return 1;
    }
    else {
        return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
    }
}
int main()
{
    int n,k;
    cin >> n >> k;
    
    COMinit();
    
    for (int i = 1;i <= k;i++){
        cout << (COM(n-k+1,i)*COM(k-1,i-1))%MOD << endl;
    }
}
