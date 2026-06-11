#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    cout << k - (k > a ? k - a : 0 ) - (k > a + b ? k - (a + b) : 0) << endl;
}