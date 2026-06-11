#include <iostream>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    ll edges = 0;
    rep(k,N-1) {
        ll i, j;
        cin >> i >> j;
        if (j < i) swap(i,j);
        edges += ll(i) * (N - j + 1);
    }
    ll vertices = 0;
    for (int k = 1; k <= N; ++k) {
        vertices += ll(N - k + 1) * (N-k+2);
    }
    vertices /= ll(2);
    cout << vertices - edges << endl;
    return 0;
}