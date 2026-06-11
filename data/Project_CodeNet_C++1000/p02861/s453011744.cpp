#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int x[10], y[10];

double aaa(int i, int j) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return pow(dx * dx + dy * dy, 0.5);
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<int> v(n);
    rep(i, n) v[i] = i+1;
    double sum = 0.0;
    do{
        for(int i = 0; i < n-1; i++) sum += aaa(v[i], v[i+1]);
    }while(next_permutation(all(v)));
    int ju = 1;
    for(int i = 2; i <= n; i++) ju *= i;
    double ans = sum / ju;
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}