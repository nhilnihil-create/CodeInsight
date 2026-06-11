#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n, a[1000005], cnt[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> n;
    int d = 0;
    bool ok = true, one = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d = __gcd(d, a[i]);
        cnt[a[i]]++;
        if (a[i] != 1) one = false;
        if (cnt[a[i]] > 1 && a[i] > 1) ok = false;
    }

    if (one) {
        cout << "pairwise coprime\n";
        return 0;
    }

    for (int i = 2; i <= maxn && ok; i++) {
        int tmp = 0;
        for (int j = i; j <= maxn && ok; j += i) {
            if (cnt[j]) tmp++;
            if (tmp >= 2) ok = false;
        }
    }

    if (ok) {
        cout << "pairwise coprime\n";
        return 0;
    }

    if (d == 1) cout << "setwise coprime\n";
    else cout << "not coprime\n";

    return 0;
}
