#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    ll A;
    double b;
    cin >> A >> b;
    b += 0.005;
    ll B = (b * 100);
    cout << (A * B)/100 << endl;
}