#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
// #define DEBUG 10
 
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
 
const int oo = 1e9 + 7;
const ll mod = 1e9+7, maxn = 20, maxm = (1 << 18);
const ld PI = acos(-1);



int main (){
    ios_base::sync_with_stdio(false);

    int n;

    cin >> n;

    vector<int> a(n), b(n);

    for (int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    sort(all(a));
    sort(all(b));

    if (n&1){
        cout << b[n/2] - a[n/2] + 1 << endl;
    }
    else {
        cout << b[n/2] + b[n/2-1] - a[n/2] - a[n/2-1] + 1<< endl;
    }
    return 0;
}