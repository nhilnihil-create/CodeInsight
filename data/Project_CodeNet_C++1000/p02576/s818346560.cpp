#include <bits/stdc++.h>
using namespace std;

template<class T>
T ceil(T a, T b) {
    return (a+b-1)/b;
} 

int main() {
    int n, x, t;
    cin >> n >> x >> t;
    int ans = t * ceil(n,x);
    cout << ans << endl;
}