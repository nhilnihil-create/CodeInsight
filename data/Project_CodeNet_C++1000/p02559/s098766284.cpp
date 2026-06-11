#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

// 1-indexedのBIT
template <typename T>
struct BIT {
    vector<T> array;
    const int N;

    // 0として初期化
    BIT(int _N) : array(_N + 1, 0), N(_N) {}

    // 左からi番目にxを加える
    void add(int i, T x){
        int lsb;
        while(i <= N){
            array[i] += x;
            lsb = i & (-i);
            i += lsb;
        }
    }

    //左からi番目までのSUMを得る
    T getSUM1(int i){
        T ret = 0;
        int lsb;
        while(i >= 1){
            ret += array[i];
            lsb = i & (-i);
            i -= lsb;
        }
        return ret;
    }

    //左からi番目からj番目のSUMを得る
    T getSUM(int i, int j){
        return getSUM1(j) - getSUM1(i-1);
    }
};


int main(){
    int N, Q;
    cin >> N >> Q;
    BIT<ll> bit(N);
    ll a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        bit.add(i+1, a);   
    }
    ll q, l, r;    
    for (int i = 0; i < Q; i++) {
        cin >> q >> l >> r;
        if(q == 0){
            bit.add(l+1, r);
        }
        else{
            printf("%lld\n", bit.getSUM(l+1, r));
        }
    }

}