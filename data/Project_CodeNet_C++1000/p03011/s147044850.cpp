#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int p, q, r;
    cin >> p >> q >> r;

    int min = INF;
    if(min > (p + q)) min = p + q;
    if(min > (q + r)) min = q + r;
    if(min > (p + r)) min = p + r;
    cout << min << endl;
    return 0;
}