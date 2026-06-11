#include <bits/stdc++.h>
#define ll long long
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define INF = 1001001001
#define pi = acos(-1)
using namespace std;
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

int main(){
    int n, k; cin>>n>>k;
    vector<double> p(n+1);
    double ans = 0.0;

    for (int i = 1; i < n+1; ++i) {
        int tmp; cin >> tmp;
        for (int j = 1; j <= tmp; ++j) {
            p[i] += (double)j/tmp;
        }
        p[i] += p[i-1];
    }

    for (int l = k; l < n+1; ++l) {
        if(p[l] - p[l-k] > ans) ans = p[l] - p[l-k];
    }

    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}