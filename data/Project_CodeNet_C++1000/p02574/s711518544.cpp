#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> a;
bool ok[1000010];

bool check_pairwise() {
    for (int i=1;i<=1000000;i++) ok[i] = true;
    for (auto x: a) {
        if (x==1) continue;
        if (!ok[x]) return false;
        for (int i=2;i*i<=x;i++) {
            if (x%i==0) {
                if (!ok[i]||!ok[x/i]) return false;
                ok[i] = false;
                ok[x/i] = false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        int x; cin >> x;
        a.pb(x);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end())-a.begin());
    reverse(a.begin(), a.end());

    bool w = check_pairwise();
    if (w&&(a.size()>1||a[0]==1)) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int gcd = a[0];
    for (auto x: a) gcd = __gcd(x, gcd);
    cout << (gcd==1? "setwise": "not") << " coprime" << endl;
}
