#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 998244353;

vector<long long int> inverse;
vector<long long int> f, f_inverse;

void factorial_Initialize(int max){
    vector<long long int> a(max+1,1);
    inverse = a;
    f = a;
    f_inverse = a;

    for (int i=2; i<=max; i++){
        inverse[i]   = MOD - inverse[MOD % i] * (MOD / i) % MOD;
        f[i]         = f[i-1]         * i          % MOD;
        f_inverse[i] = f_inverse[i-1] * inverse[i] % MOD;
    }
}

long long int nCr(int n, int r){
    if(n < r || r < 0) return 0;
    if (n >= f.size()){
        factorial_Initialize(n);
    }
    return f[n] * f_inverse[r] % MOD * f_inverse[n-r] % MOD;
}

long long int modpow(long long int b, long long int p){
    long long int num = 1, power = b;
    for(int i=0; i<=30; i++){
        if((p>>i) & 1){
            num *= power;
            num %= MOD;
        }

        power *= power;
        power %= MOD;
    }
    return num;
}

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> d(n);
    vector<long long int> depth(n);
    for(int i=0; i<n; i++){
        cin >> d[i].first;
        d[i].second = i;
        depth[d[i].first] += 1;
    }
    sort(d.begin(),d.end());
    //for(int i=0; i<n; i++) cout << d[i].first << " " << d[i].second << endl;

    if(d[0].first != 0 || d[0].second != 0 || d[1].first == 0){
        cout << 0 << endl;
        return 0;
    }

    bool flag = true;
    long long int ans = 1;
    for(int i=1; i<n; i++){
        if(flag == false && depth[i] != 0){
            cout << 0 << endl;
            return 0;
        }
        ans *= modpow(depth[i-1], depth[i]);
        ans %= MOD;
        if(depth[i] == 0) flag = false;
    }
    cout << ans << endl;
    return 0;
}