#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n, tmp, x[100], y[100];
    double p, q, r, s;
    s = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }
    for (int i=0; i<n; i++) {
        cin >> tmp;
        x[i] = x[i] - tmp;
    }
    for (int i=0; i<n; i++) {
        p += abs(x[i]);
        q += pow(abs(x[i]), 2);
        r += pow(abs(x[i]), 3);
        if (s < abs(x[i])) {
            s = abs(x[i]);
        }
    }
    cout << fixed << p << endl;
    cout << fixed << sqrt(q) << endl;
    cout << fixed << cbrt(r) << endl;
    cout << fixed << s << endl;
    
    
}
