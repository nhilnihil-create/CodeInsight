#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll A, B, M;
    cin >> A >> B >> M;
    ll a[A], b[B];
    ll x[M], y[M], c[M];
    rep(i, A){
        cin >> a[i];
    }
    rep(i, B){
        cin >> b[i];
    }
    rep(i, M){
        cin >> x[i] >> y[i] >> c[i];
    }

    ll discount_cost[M];
    rep(i, M){
        discount_cost[i] = a[x[i] - 1] + b[y[i] - 1] - c[i];
    }
    sort(a, a + A);
    sort(b, b + B);
    sort(discount_cost, discount_cost + M);
    ll no_discount_min_cost = a[0] + b[0];
    ll discount_min_cost = discount_cost[0];

    cout << min(no_discount_min_cost, discount_min_cost) << endl;

    return 0;
}