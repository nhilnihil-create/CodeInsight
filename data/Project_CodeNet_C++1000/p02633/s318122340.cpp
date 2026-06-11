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
    ll x;
    cin >> x;
    ll y = x;
    ll k = 1;
    while(y % 360 != 0){
        k++;
        y += x;
    }
    cout << k << endl;
    return 0;
}
