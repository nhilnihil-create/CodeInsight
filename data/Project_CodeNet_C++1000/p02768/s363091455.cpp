#include <iostream>
using namespace std;

const long long MOD = 1000000007;
const long long MAX = 200000;

long long inv[MAX+10], power[MAX + 10];

void prepare(){
    inv[1] = 1;
    power[0] = 1;
    power[1] = 2;
    for(int i =2; i < MAX+ 5 ; i++){
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        power[i] = power[i-1]*2%MOD;
    }
}

int COM(long long n, long long k){
    if(k == 0) return 1;
    else return (n-k+1)*inv[k]%MOD*COM(n,k-1)%MOD;
}

int main(){
    prepare();
    long long n;
    cin >> n;
    long long a, b;
    cin >> a >> b;
    long long twon = 1;
    long long q = n/MAX;
    long long r = n%MAX;
    for(int i =0; i < q; i++){
        twon = twon*power[MAX]%MOD;
    }
    for(int i =0; i < r; i++){
        twon =twon*2%MOD;
    }
    cout << (2*MOD + twon - 1 - COM(n,a) - COM(n,b))%MOD << endl;
}