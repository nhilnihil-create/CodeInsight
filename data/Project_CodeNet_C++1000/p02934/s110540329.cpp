#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;cin >> n;
    vector<double> a(n);
    rep(i, n){
        cin >> a.at(i);
    }
    double sum = 0;
    rep(i, n){
        sum += (1/a.at(i));
    }
    sum = 1 / sum;
    printf("%.6lf", sum);
    return 0;
}
