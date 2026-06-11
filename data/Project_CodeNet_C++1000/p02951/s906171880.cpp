#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main(){
    int A, B, C;
    cin >> A >> B >> C;
    cout << max(C - (A - B), 0 )<< endl;
}
