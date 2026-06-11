#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7, maxn = 100000;
const long double PI = acos(-1);

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double l;
    cin >> l;
    l/=3.0;

    cout << fixed << setprecision(10) << l*l*l << endl;
    return 0;
}