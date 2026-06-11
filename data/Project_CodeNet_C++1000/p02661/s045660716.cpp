#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (n % 2){
        cout << b[(n-1) / 2] - a[(n-1) / 2] + 1 << endl;
    } else{
        cout << (b[n/2 - 1] + b[n/2]) - (a[n/2 - 1] + a[n/2]) + 1 << endl;
    }
}