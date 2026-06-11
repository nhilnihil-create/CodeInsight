#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int factorial(int n){
    int ans = 1;
    rep(i, 0, n) ans *= i+1;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) a[i] = i;
    vector<double> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    double dist = 0;
    do{
        rep(i, 0, n-1){
            dist += pow(pow(x[a[i]] - x[a[i+1]], 2) + pow(y[a[i]] - y[a[i+1]], 2), 0.5);
        }
    }while(next_permutation(a.begin(), a.end()));
    printf("%.10f\n", dist/factorial(n));
    return 0;
}
