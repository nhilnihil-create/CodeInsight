#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#define all(x) x.begin(), x.end()
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;

constexpr int SIZE = 1e6+1;

int main(){
    int n; cin >> n;
    int cnt[SIZE] = {0};
    int a[n];
    rep(i, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    loop(i, 1, SIZE)for(int j = 2*i; j < SIZE; j += i) cnt[j] += cnt[i];

    int ans = 0;
    for(int num : a) if(cnt[num] == 1) ans++;
    cout << ans << endl;
    return 0;
}