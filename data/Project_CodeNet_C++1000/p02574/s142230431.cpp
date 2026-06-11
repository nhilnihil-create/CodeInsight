#include <bits/stdc++.h>
#define sp putchar(' ')
#define en putchar('\n')
#define MOD(x) ((((x)%Mod)+Mod)%Mod)
#define int64_t int
const int MAXN = 1000005 ;
using namespace std ;

int n , m ;
int64_t a ;
bool isP[MAXN] ;
vector<int> primes ;
void getP() {
    memset(isP, true, sizeof(isP)) ;
    isP[0] = isP[1] = false ;
    primes.clear() ;
    for(int i = 2; i < MAXN; ++ i) {
        if(!isP[i]) continue ;
        primes.push_back(i) ;
        for(int j = 2;1LL*j*i < MAXN; ++ j) {
            isP[j * i] = false ;
        }
    }
}

int factor[20][2] ;
int factCnt ;

int getFactor(int x)
{
    factCnt = 0 ;
    for(int i = 0;primes[i] < x; ++ i) {
        if (isP[x]) break ;
        if (x % primes[i] == 0) {
            for (factor[factCnt][1] = 0;x % primes[i] == 0;x /= primes[i]) {
                ++ factor[factCnt][1] ;
            }
            factor[factCnt ++ ][0] = primes[i] ;
        }
    }
    if (x != 1) {
        factor[factCnt][1] = 1 ;
        factor[factCnt ++ ][0] = x ;
    }
    return factCnt ;
}

unordered_set<int64_t> s ;
int main()
{
    getP() ;
//    getFactor(24) ;

    ios::sync_with_stdio(false) ;
    while(cin >> n) {
        s.clear() ;
        int64_t gcds ;
        bool isOk = true ;
        for(int i = 1;i <= n; ++i) {
            cin >> a ;
            getFactor(a) ;
//            cout << "factors of "<< a<<":" << endl ;
//            for(int i = 0;i < factCnt; ++i) {
//                cout << factor[i][0] << "," << factor[i][1] << endl ;
//            }
            gcds = (i == 1)?a:__gcd(gcds, a) ;
            for(int j = 0;j < factCnt; ++j)  {
                if(s.count(factor[j][0])) {
                    isOk = false ;
                    break ;
                }
                s.insert(factor[j][0]) ;
            }
        }
        if(isOk) {
            cout << "pairwise coprime" << endl ;
        } else if(gcds == 1) {
            cout << "setwise coprime" << endl ;
        } else {
            cout << "not coprime" << endl ;
        }
    }
}
