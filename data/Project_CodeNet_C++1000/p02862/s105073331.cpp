#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);
const int MAX = 1000100;
const int MOD = 1e9 + 7;
using P = pair<int,int>;
map<P,ll> m;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
    int x,y;
    cin >> x >> y;
    if((x+y)%3!=0) {
        cout << 0 << endl;
        return 0;
    }
    //int p = (x+y)/3;
    int a = (2*x - y) / 3;
    int b = (2 * y - x) / 3;
    COMinit();
    cout << COM(a+b,a) << endl;
}