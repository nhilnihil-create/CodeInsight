#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);


int main(){
    ll s;cin >> s;
    const ll mod = 1000000007;
    vec A(s+1);
    A[0] = 1;
    for(int i = 3;i <= s;i++){
        for(int j = i - 3;j >= 0;j--){
            A[i] += A[j];
            A[i] %= mod;
        }
        A[i] = (A[i] + mod)%mod;
    }
    cout << A[s] << endl;

}
