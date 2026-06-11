#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define open freopen("input.in", "r", stdin); freopen("output.out", "w", stdout);
using namespace std; typedef long long ll; typedef long double ld; mt19937 rnd(time(0));

#define int ll

void solve(){
    int n, k, c;
    char ch;
    cin >> n >> k >> c;
    int right[k + 1], left[k + 1], a[n + 1];
    right[0] = n + 1; left[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> ch;
        if (ch == 'o')
            a[i] = 0;
        else
            a[i] = 1;
    }
    int now = 1;
    for (int i = 1; i <= n; i++){
        if (a[i] == 0 && (now == 1 || i - left[now - 1] - 1 >= c)){
            left[now] = i;
            if (now == k)
                break;
            now++;
        }
    }
    now = 1;
    for (int i = n; i >= 1; i--){
        if (a[i] == 0 && (now == 1 || right[now - 1] - i - 1 >= c)){
            right[now] = i;
            if (now == k)
                break;
            now++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = 0;
        int r = k + 2;
        while (r > l + 1) {
            int mid = (r + l) / 2;
            if (left[mid] < i)
                l = mid;
            else
                r = mid;
        }
        int l1 = l;
        l = 0;
        r = k + 2;
        while(r > l + 1){
            int mid = (r + l) / 2;
            if (right[mid] > i){
                l = mid;
            }else{
                r = mid;
            }
        }
        int r1 = l;
        if (l1 + r1 > k || (l1 + r1 == k && (l1 == 0 || r1 == 0 || right[r1] - left[l1] - 1  >= c))){
            continue;
        }else{
            cout << i << endl;
        }
    }
}

signed main(){
    ios;
    // open;
    ll t = 1;
    // cin >> t;
    cout.precision(16);
    while(t--){
        solve();
    }
    return 0;
}