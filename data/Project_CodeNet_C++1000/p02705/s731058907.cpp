//#define local
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using P = pair<long long,long long>;
template <class T> using vec = vector<T>;
#ifdef local
#include "debug.cpp"
#else
#define debug(...)
#endif

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(10);
    double r; cin >> r;
    debug(x);
    cout << 2 * r * acos(-1) << endl;
}