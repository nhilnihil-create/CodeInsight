#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    
    vec<int> P(N);
    rep(i, N) cin >> P[i];
    
    vec<int> Q(N);
    rep(i, N) cin >> Q[i];

    vec<int> c(N);
    iota(all(c),1);

    int cnt = 0;
    int p;
    int q;
    do {
        ++cnt;
        if(equal(all(P),all(c))) p=cnt;
        if(equal(all(Q),all(c))) q=cnt;

    }while(next_permutation(all(c)));
    cout << abs(p-q) << endl;
}
