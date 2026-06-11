#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n, d, ans;
    cin >> n >> d;
    vector<vector<int>> data(n, vector<int>(d));
    rep(i, n){
        rep(j,d){
            cin >> data[i][j];
        }
    }

    ans = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int p = 0;
            rep(k, d){
                p += pow(data[i][k] - data[j][k], 2.0);
            }
            double r = floor(sqrt(p));
            if(pow(r, 2.0) == p){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
