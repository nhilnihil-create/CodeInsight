#include "bits/stdc++.h"
using namespace std;
using LL = long long;
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)

int d, t, s;

int main(){
    cin >> d >> t >> s;
    cout << (t * s >= d ? "Yes" : "No") << endl;
}