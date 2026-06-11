// ABC166C.cpp

#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool>tower(n,true); // 良い展望台か
    vector<ll>h(n); // 高さ
    rep(i, n) cin >> h[i];
    int a, b;
    rep(i, m) {
        cin >> a >> b;
        --a;
        --b;
        if (h[a] <= h[b]) tower[a] = false;
        if (h[b] <= h[a]) tower[b] = false;
    }
    int ans = 0;
    rep(i, n) {
        if (tower[i] == true) ans++;
    }
    cout << ans << endl;

}
