#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    for(int i=0; i<N; i++) {
        cin >> X[i];
    }
    vector<int> Y(N);
    Y = X;
    sort(Y.begin(), Y.end());
    int min_n = Y[0];
    int max_n = Y[N-1];
    ll min_p = INF;

    for(int i=min_n; i<=max_n; i++) {
        ll p = 0;
        for(int j=0; j<N; j++) {
            p += pow(abs(i-Y[j]),2);
        }
        min_p = min(min_p, p);
    }
    cout << min_p << endl;
}