#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

const ll mod = 1e9+7;

int main()
{
    ll N,K;
    cin >> N >> K;
    vint A(N);
    cin >> A;
    vint cnt(N);
    vint bias(N);
    REP(i,N){
        REP(j,N){
            if(A[i] > A[j])cnt[i]++;
            if(i < j && A[i] > A[j])bias[i]++;
        }
    }
    ll ans = 0;
    REP(i,N){
        ll mul = (K*(K-1)/2)%mod;
        ans += cnt[i]*mul;
        ans %= mod;
        ans += bias[i]*K;
        ans %= mod;
    }
    cout << ans << endl;
}