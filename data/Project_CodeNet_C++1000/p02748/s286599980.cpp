#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template<typename T> void print(const T & v);


int main() {
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);
    rep(i, A) cin >> a[i];
    rep(i, B) cin >> b[i];

    vector<int> x(M), y(M), c(M);
    rep(i, M) cin >> x[i] >> y[i] >> c[i];
    int mini_a = INF;
    int total = 0;
    rep(i, A){
        mini_a = min(mini_a, a[i]);
    }
    int mini_b = INF;
    rep(i, B){
        mini_b = min(mini_b, b[i]);
    }
    total = mini_a + mini_b;

    int set_mini = INF;
    rep(i, M){
        int price = a[x[i] - 1] + b[y[i] - 1] - c[i];
        set_mini = min(set_mini, price);
    }
    cout << min(total, set_mini) << endl;
    return 0;
}


// Use For Debug
template <typename T>
void print(T const & v){
    for(int i = 0; i < v.size(); i++){
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
