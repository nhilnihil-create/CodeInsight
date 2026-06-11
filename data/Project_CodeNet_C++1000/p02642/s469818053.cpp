#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

map<int, int> factor(int n){
    map<int, int> res;

    for (int i = 2; i*i <= n; ++i) {
        while(n % i == 0){
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m = max(m, a[i]);
    }
    sort(all(a));

    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }

    if(a[0] == a[n-1]){
        cout << 0 << "\n";
        return 0;
    }

    vector<int> b(m+1);
    b[0] = false;
    for (int i = 0; i < n; ++i) {
//        int x = 1;
//        for (int j = a[i]; j <= m; j*=x) {
//            b[j] = false;
//            x++;
//        }

        int j = a[i], x = 1;
        while(j <= m){
            b[j]++;
            x++;
            j = a[i] * x;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(b[a[i]] > 1){
            ans++;
        }
    }

    ans = n - ans;
    cout << ans << "\n";

    return 0;
}
