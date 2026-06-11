# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)

struct INIT{
    INIT(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(13);
    }
}INIT;
LL n, k;
LL a[1010];
LL sum = 0;
 
bool cond(LL d){
    vector<LL> v;
    for(int i = 1;i <= n;i++)v.emplace_back(a[i]%d);
    sort(ALL(v));
    vector<LL> rui(n + 1, 0);
    for(int i = 1;i <= n;i++){
        rui[i] = rui[i - 1] + v[i - 1];
    }
    for(int i = 0;i <= n;i++){
        LL a = rui[i];
        LL b = (n - i)*d - (rui[n] - rui[i]);
        //cout << d << " " << a << " " << b << endl; 
        if(a == b && max(a, b) <= k)return true;
    }
    return false;
}
 
int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum += a[i];
    }
    LL ans = 0;
    for(LL i = 1;i * i <= sum;i++){
        if(sum % i == 0){
            if(cond(i))ans = max(ans, i);
            if(cond(sum/i))ans = max(ans, sum/i);
        }
    }
    cout << ans << endl;
}