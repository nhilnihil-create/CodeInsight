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
    
    int n; cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> x, y;
    rp(i, 0, n) {
        int a, b;
        cin >> a >> b;
        x.emplace_back(a);
        y.emplace_back(b);
    }
    
    vector<int> P, Q;

    rp(i, 0, n){
        rp(j, i+1, n){
            P.emplace_back(x[i] - x[j]);
            Q.emplace_back(y[i] - y[j]);
        }
    }
    int cost = n;
    int size = P.size();
    rp(i, 0, size){
        int p = P[i];
        int q = Q[i];
        int count = 0;
        rp(j, 0, size){
            if(p == P[j] && q == Q[j]) count ++;
            if(p == -P[j] && q == -Q[j]) count ++;
        }
        chmin(cost, n-count);
    }
    cout << cost << endl;
    return 0;
}