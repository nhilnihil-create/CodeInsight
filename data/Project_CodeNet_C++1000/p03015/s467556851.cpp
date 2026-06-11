#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int> >;
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(int i = m; i < (int)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum accumulate
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
typedef long long ll;
const int INF = 2000000000;
const ll INF64 = 9223372036854775806ll;
const ll MOD = 1000000007LL;
/*メモ XOR問題のまとめ
性質 1「交換則、結合則が成り立つ」
　　 2「a xor a = 0」
　　 3「ある数xのb番目のビットが1である <=> x mod 2^(b+1) ≧ 2^b」
　　 4「0≦aのとき、4a, 4a+1, 4a+2, 4a+3のxor和は0」
方針 
!!!!!1「xor計算は各ビットで独立なので別々に計算」
　　 2「trieを使ったxorの最大最小探索がある解説」
*/
long long modpow(long long a, long long n, long long mod) { //累乗の余剰
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main(){
    string s;
    std::cin >> s;
    int n=s.size();
    ll ans=0;
    ll po=0;
    rep(i,n){
        if(s[i]=='1'){
            ans+=(modpow(3,n-i-1,MOD)*modpow(2,po,MOD))%MOD;
            ans+=(2*modpow(2,po-1,MOD))%MOD;
            po++;
        }
        ans%=MOD;
    }
    std::cout << ans << std::endl;
}