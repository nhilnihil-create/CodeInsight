#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

long long modpow(long long a,long long n,long long mod){
    
    long long res = 1;
    while(n > 0){
        //if(n&1)
        res = res*a%mod;
        //a = a * a % mod;
        n -= 1;
    }
    return res;
}

int main(){
    int N;
    cin >> N;
    int D[N];
    long long mod = 998244353;
    map<long long,int> d;
    for(int i = 0; i < N;i++){
        cin >> D[i];
        d[D[i]]++;
    }
    long long ans = 1;
    bool flag = false;
    for(int i = N -1; i >= 1;i--){
        if(d[i]!=0)flag = true;
        if(flag&&d[i]==0){
            cout << 0 << endl;
            return 0;
        }
    }
    if(d[0]!=1){
        cout << 0 << endl;
        return 0;
    }
    if(D[0]!= 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <N;i++){
        ans *= modpow(d[i-1],d[i],mod);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}