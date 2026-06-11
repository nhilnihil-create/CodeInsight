#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

int main() {
    int N;
    cin >> N;
    vector< vector <int> > dis(20, vector<int>(20));
    for(int i = 1; i <= N; i++) {
        int matsubi = i % 10;
        int sentou = i;
        while(sentou >= 10) sentou /= 10;
        dis[sentou][matsubi] += 1;
    }
    int res = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            res += dis[i][j] * dis[j][i];
        }
    }
    cout << res << endl;
    return 0;
}