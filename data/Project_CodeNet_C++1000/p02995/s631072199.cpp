#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++){
        for (int k = 0; k < B.size(); k++){
            for (int j = 0; j < B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n){
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

ll lcm(ll x, ll y){
    return x * (y / gcd(x, y));
}

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll numa, numb;
    // cout << gcd(2, 3) << endl;
    // cout << lcm(2, 3) << endl;
    numa = (a - 1) / c + (a - 1) / d - (a - 1) / lcm(c, d);
    numb = b / c + b / d - b / lcm(c, d);
    ll sm = numb - numa;
    ll ans = b - a + 1 - sm;
    // cout << numa << " " << numb << endl;
    cout << ans << endl;
}