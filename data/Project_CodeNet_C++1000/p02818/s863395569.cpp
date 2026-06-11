#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    ll A, B, K;
    cin >> A >> B >> K;
    cout << max(A - K, (ll)0) << ' ' << max(B - max((K - A), (ll)0), (ll)0) << endl;
}
