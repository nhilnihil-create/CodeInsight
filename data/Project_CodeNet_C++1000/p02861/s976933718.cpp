#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int x[8], y[8];

double dist(int i, int j) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return pow(dx * dx + dy * dy, 0.5);
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    double sum = 0.0;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        v[i] = i + 1;
    do {
        rep(i,n-1){
            sum += dist(v[i],v[i+1]);
        }
    } while(next_permutation(v.begin(), v.end()));
    int factorial = 1;
    rep(i,n){
        factorial *= (i+1);
    }
    double avg = sum / factorial;
    cout << fixed << setprecision(10) << avg <<endl;
}