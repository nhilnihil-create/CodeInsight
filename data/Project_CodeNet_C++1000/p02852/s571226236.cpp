#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <cstring>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
typedef long long ll;
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

template<typename T> //最大公約数
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T> //最小公倍数
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

const int COM_MAX = 500500;
long long fac[COM_MAX],finv[COM_MAX],inv[COM_MAX];
void init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < COM_MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

long long COM(int n,int k){
    if(n < k || n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}


// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

struct Coordinate {
    int y, x;
};

int main(){
    int N, M; cin >> N >> M;
    string S; cin >> S;
    if (N+1 <= M){
        cout << N << endl;
        return 0;
    }

    int pos = S.size()-1;
    vector<int> ans(0);
    while (true){
        bool flg = false;
        for (int i = M; i >= 1; i--){
            if (S[pos-i] == '1'){
                continue;
            } else if (pos-i < 0){
                continue;
            } else if (S[pos-i] == '0'){
                ans.push_back(i);
                pos -= i;
                flg = true;
                i = 0;
            }
        }
        if (!flg || pos == 0) break;
    }

    if (pos > 0){
        cout << -1 << endl;
        return 0;
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}