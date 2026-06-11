#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >> n, n != 0){
        valarray<double> s(n);
        for(int i = 0; i < n; i++) cin >> s[i];
        double m = s.sum() / n;
        s = (s - m) * (s - m);
        cout << fixed << setprecision(4) << sqrt(s.sum()/n) << endl;
    }
}