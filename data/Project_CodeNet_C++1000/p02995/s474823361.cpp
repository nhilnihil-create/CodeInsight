#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    long long e = lcm(c,d);
    long long cc = (b/c) - ((a+c-1)/c) + 1;
    long long dd = (b/d) - ((a+d-1)/d) + 1;
    long long ee = (b/e) - ((a+e-1)/e) + 1;
    cout << b - a + 1 - cc - dd + ee << endl;
}