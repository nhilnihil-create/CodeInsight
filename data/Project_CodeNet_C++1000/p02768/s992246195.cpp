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

long long n;

long long modpow(long long a, long long n,long long mod)
{
    long long res = 1;
    while(n > 0){
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long ruisekiMOD(long long b,long long a)
{
    long long ans = 1;
    
    for (long long i = a;i <= b;i++){
        ans = ans*i%MOD;
    }
    return ans;
}

int main()
{
    long long a,b;
    
    cin >> n >> a  >> b;
    
    long long ax = ruisekiMOD(n,n-a+1);
    long long ay = ruisekiMOD(a,1);
    long long bx = ruisekiMOD(n,n-b+1);
    long long by = ruisekiMOD(b,1);
    
    long long ans = MOD + MOD + modpow(2,n,MOD) - ax*modpow(ay,MOD-2,MOD)%MOD - bx*modpow(by,MOD-2,MOD)%MOD - 1;
    
    cout << ans%MOD << endl;
   
}
