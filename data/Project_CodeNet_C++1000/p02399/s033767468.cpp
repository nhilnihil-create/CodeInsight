#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, d, r;
    double A, B, f;
    cin >> a >> b;
    d = a / b;
    r = a % b;
    A = a;
    B = b;
    f = A / B;
    cout << d << " " << r << " " << fixed << f << endl;
    return 0;
}
