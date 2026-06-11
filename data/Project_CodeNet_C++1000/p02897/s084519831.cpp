#include <bits/stdc++.h>
using namespace std;
int main(){
        int n; cin >> n;
        int odd = (n + 2 - 1) / 2;
        long double p = (long double)odd / (long double)n;
        cout << fixed << setprecision(20) << p << endl;
    return 0;
}
