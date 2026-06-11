#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    long long A, B, N;
    cin >> A >> B >> N;
    ll x = min(B-1,N);
    ll F = (A*x)/B - A*(x/B);
    cout << F << endl;
}