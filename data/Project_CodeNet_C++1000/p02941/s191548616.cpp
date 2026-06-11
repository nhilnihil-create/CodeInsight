#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

void no(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> a(n), b(n);

    for (int j = 0; j < 2; ++j){
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        a.swap(b);
    }

    set<pii> s;

    for (int i = 0; i < n; ++i){
        s.insert(pii(-b[i], i));
    }

    int64 steps = 0;

    while (!s.empty()){
        auto x = *s.begin();
        s.erase(x);

        int v = -x.first;
        int p = x.second;

        if (v < a[p]){
            no();
        } else if (v == a[p]){
            continue;
        }

        int ri = b[(p - 1 + n) % n];
        int le = b[(p + 1) % n];
        int delta = ri + le;
        int k = (b[p] - a[p]) / delta;

        if (k <= 0) no();

        b[p] -= delta * k;
        steps += k;

        s.insert(pii(-b[p], p));
    }

    cout << steps << endl;

    return 0;
}