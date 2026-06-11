#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int N, R;
    cin >> N >> R;
    if(N >= 10) cout << R << endl;
    else cout << R + 100 * (10 - N) << endl;
}
