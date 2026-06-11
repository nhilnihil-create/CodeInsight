#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
//constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
ll INF = 6001001001001001001;
long double EPS = 1e-6;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll N;
string S;
ll fact[1000010];

void fill(){
    fact[0] = 0;
    FOR(i,1,1000010){
        ll cnt = 0,I = i;
        while(I % 2 == 0 && I != 0){
            cnt++;
            I /= 2;
        }
        fact[i] = cnt + fact[i-1];
    }
}

int main(){
    cin >> N >> S;
    rep(i,N){
        S[i] = S[i] - 1;
    }
    fill();
    ll  cnt = 0;
    rep(i,N) if(S[i] == '1' && fact[N-1] == fact[i] + fact[N-i-1]) cnt++;
    if(cnt % 2 == 1){
        cout << 1 << endl;
        return 0;
    }
    bool flag = 0;
    rep(i,N) if(S[i] == '1') flag = 1;
    if(flag){
        cout << 0 << endl;
        return 0;
    }
    rep(i,N) if(S[i] == '2') S[i] = '1';
    cnt = 0;
    rep(i,N) if(S[i] == '1' && fact[N-1] == fact[i] + fact[N-i-1]) cnt++;
    if(cnt % 2 == 1){
        cout << 2 << endl;
        return 0;
    }
    cout << 0 << endl;
}
