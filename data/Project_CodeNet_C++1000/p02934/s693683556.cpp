#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    double sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += 1.0 / a[i];
    }
    double ans = 1.0 / sum;
    printf("%.10f\n", ans);
    return 0;
}