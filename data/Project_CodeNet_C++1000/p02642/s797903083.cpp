#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

bool checked[1000010];

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (i < n - 1){
            if (a[i] == a[i+1]){
                checked[a[i]] = true;
                continue;
            }
        }
        if (!checked[a[i]]){
            res++;
        }
        for (int j = a[i]; j < 1000010; j += a[i]) {
            checked[j] = true;
        }
    }
    cout << res << endl;
}