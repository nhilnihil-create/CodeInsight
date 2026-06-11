#include<bits/stdc++.h>
using namespace std;
int f(int n){
    if(n == 2)
        return 2;
    return f(n - 1) * n;
}
int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    long double ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int d = dx * dx + dy * dy;
            ans += sqrtl(d);
        }
    }
    ans *= 2;
    ans /= n;
    cout << fixed;
    cout << setprecision(8) << ans << endl;
    return 0;
}