#include <map>
#include <cmath>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long x;
    cin >> x;
    cout << (360 / (__gcd(x, 1LL * 360)) * x) / x << endl;
    return 0;
}
