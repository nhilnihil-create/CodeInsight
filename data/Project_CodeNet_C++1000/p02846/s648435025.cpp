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

LL T1, T2, A1, A2, B1, B2;

int main(){
    cin >> T1 >> T2;
    cin >> A1 >> A2;
    cin >> B1 >> B2;
    if(T1 * A1 + T2 * A2 == T1 * B1 + T2 * B2){
        cout << "infinity" << endl;
        return 0;
    }
    LL SA1 = (T1 * A1 - T1 * B1), SA2 = (T1 * A1 + T2 * A2 - T1 * B1 - T2 * B2);
    if((SA1 > 0 && SA2 > 0) || (SA1 < 0 && SA2 < 0)){
        cout << 0 << endl;
        return 0;
    }
    if(SA1 > 0){
        SA2 += SA1;
        if(SA1 % (SA1 - SA2) == 0){
            cout << SA1 / (SA1 - SA2) * 2LL << endl;
        }else{
            cout << SA1 / (SA1 - SA2) * 2LL + 1 << endl;
        }
    }else{
        SA2 *= -1;
        SA1 *= -1;
        SA2 += SA1;
        if(SA1 % (SA1 - SA2) == 0){
            cout << SA1 / (SA1 - SA2) * 2LL << endl;
        }else{
            cout << SA1 / (SA1 - SA2) * 2LL + 1 << endl;
        }
    }
    
}