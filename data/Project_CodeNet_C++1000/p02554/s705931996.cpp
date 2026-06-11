#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long pow_pro(int N);

int main(){
    int N;
    cin >> N;
    long long c1 = 1;
    long long c2 = 2;
    long long c3 = 1;
    long long c;
    for(int i = 0; i < N; i++)c1 = c1 * 10 % MOD;
    for(int i = 0; i < N; i++)c2 = c2 * 9 % MOD;
    for(int i = 0; i < N; i++)c3 = c3 * 8 % MOD;    
    c = c1 - (c2 - c3);
    c %= MOD;
    c = (c + MOD)%MOD;

    cout << c << endl;
    return 0;
}
