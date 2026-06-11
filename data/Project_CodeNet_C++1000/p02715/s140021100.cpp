#include <iostream>
#include <algorithm>
#include <vector> //動的配列
#include <string>
#include <list> //双方向リスト
#include <map> //連想配列
#include <set> //集合
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <numeric>
#include <tuple>



typedef long long ll;


using namespace std;

typedef pair<int, int> P;
#define FOR(i,a,b) for(int i=(int)(a) ; i < (int) (b) ; ++i )
#define rep(i,n) FOR(i,0,n)
#define sz(x) int(x.size())


template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

//小さい順から取り出すヒープ
//priority_queue<ll, vector<ll>, greater<ll> > pque1;

const ll mod = 1e9+7;

ll modpow(ll x, ll n, ll mod){
    ll res = 1;
    while (n>0){
        if (n&1) res = res* x % mod;
        x = x* x% mod;
        n = n>>1;
    }
    return res;
}

int main(){
    ll n,k;
    cin >> n>>k;
    vector<ll> di(k+1,0);
    
    
    for (int i=1; i<=k; i++){
        di[i] = modpow( ll(k/i), n, mod);
    }
    
    
    for (int i=k; i>0;i--){
        for (int j=2*i; j<=k; j+=i){
            di[i] += mod-di[j];
            if (di[i]<0) di[i] += mod;
            di[i] %= mod;
        }
    }
    
    //for (auto x:di) cout<<x<<" ";
    ll ans=0;
    for(int i=1; i<=k;i++){
        ans = ( ans+ i*di[i]) % mod;
    }
    
    cout<<ans<<endl;
    
    return 0;
}
