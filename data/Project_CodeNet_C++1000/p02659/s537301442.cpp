#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    ll A;
    double b;
    cin >> A >> b;
    ll ib = b * 100 +.000001; //暗黙の型変換をするが切り捨て
    cout << (A * ib)/100 << endl;
}
