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

int n;
int x[101], y[101];

int main(){
    cin >> n;
    REP(i, n){
        cin >> x[i] >> y[i];
    }
    double ans = 0.0;
    REP(i, n){
        if(x[i] == 0 && y[i] == 0)continue;
        double a = -atan2(x[i], y[i]) + 1e-9;
        double tmpx1 = 0.0, tmpy1 = 0.0, tmpx2 = 0.0, tmpy2 = 0.0;
        REP(j, n){
            double sin_theta = cos(a) * y[j] - sin(a) * x[j];
            double cos_theta = cos(a) * x[j] + sin(a) * y[j];
            if(cos_theta > 0.0){
                tmpx1 += cos_theta;
                tmpy1 += sin_theta;
            }else{
                tmpx2 += cos_theta;
                tmpy2 += sin_theta;
            }
        }
        ans = max(ans, hypot(tmpx1, tmpy1));
        ans = max(ans, hypot(tmpx2, tmpy2));
    }
    cout << ans << endl;
}