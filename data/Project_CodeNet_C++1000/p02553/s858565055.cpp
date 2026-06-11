#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max({a * c, a * d, b * c, b * d}) << endl;
    return 0;
}
