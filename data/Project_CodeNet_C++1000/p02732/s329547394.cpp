#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 2e+5 + 1;
int cnt[MAX];

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ans += 1LL * cnt[i] * (cnt[i]-1) / 2;
    }
    for(int i = 0; i < n; i++){
        cout << ans - cnt[a[i]] + 1 << endl;
    }
    return 0;
}