#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main(){
    int A, B;
    cin >> A >> B;
    if(abs(A-B) % 2 == 0) cout << (A + B) / 2 << endl;
    else cout << "IMPOSSIBLE" << endl;
}
