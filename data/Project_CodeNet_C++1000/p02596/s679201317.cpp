#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <functional>
#include <fstream>
#include <cstdlib>
typedef long long ll;
const ll MOD = 1e9+7;


#define REP(i, N) for (ll i = 0; i < (N); i++)
#define REPP(i, a, b) for (ll i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define VSORT(c) sort((c).begin(),(c).end())
#define SZ(x) ((ll)(x).size())
//vvintを作る　マクロで　 #define vvint(N,M) vector<vector<ll>>

using namespace std;
// 変数初期化
vector<ll> bsv; // binary_search用のvector
ll a,b,c,n,m;
typedef pair<ll, ll> Pll;
vector<Pll> facts; // 素因数分解の結果格納用(基数:乗数)
vector<vector<ll> > bit_search_v; //nit全探索の結果格納用

// index が条件を満たすかどうか
bool isOK(ll index, ll key) {
    if (bsv[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(int key) {
    int ng = -1;
    int ok = (ll)bsv.size();

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    // OK(key以上となる)のindex番号を返す
    return ok;
}

// 最大公約数
int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

// 最小公倍数
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}


// 階乗計算
ll fuctorial(ll n) {
    ll ans = 1;
    for(ll i = 1; i <= n;i++){
        ans *= i;
        }

        return ans;
        }

// コンビネーション
vector<vector<ll> > comb(ll n, ll r) {
    vector<vector<ll> > v(n + 1,vector<ll>(n + 1, 0));
    for (ll i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (ll j = 1; j < v.size(); j++) {
        for (ll k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}

//　素因数分解
void prime_fact(ll target){
    ll base=2, exp=0;
    while (base*base<=target) {
        while (target%base==0) {
            target /= base; exp++;
        }
        if (exp>0) {
            facts.push_back(make_pair(base, exp));
        }
        base++; exp=0;
    }
    if (target>1) facts.push_back(make_pair(target,1));
}
// prime_factの結果の確認用
void print_facts(){
    for (int i=0; i<facts.size(); i++) {
        cout << facts[i].first << " " << facts[i].second << endl;
    }
}

// bit全探索
void bit_search(ll target){
    for (ll i=0; i<(1<<target); ++i) {
        if (i==0) continue;
        vector<ll> v;
        for (ll j=0; j<target; ++j) {
            if (i&(1<<j)) v.push_back(j);
            if (i&(1<<j)) cout << i << "  :  " << j << endl;
        }
        bit_search_v.push_back(v);
    }
}
// bit全探索の結果確認用
void print_bit_search(){
    for (ll i=0; i<bit_search_v.size(); ++i) {
        for (ll j=0; j<bit_search_v[i].size(); ++j) {
            cout << bit_search_v[i][j] << " ";
        }
        cout << endl;
    }
}



int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll k;
    cin >> k;
    ll now = 0;

    for(ll i = 0; i <= k;i++){
        now = (now*10+7)%k;
        
        if(now == 0){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;



    return 0;
}