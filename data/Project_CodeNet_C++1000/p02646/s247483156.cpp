#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    if(v > w && (v-w) * t >= abs(a-b)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}