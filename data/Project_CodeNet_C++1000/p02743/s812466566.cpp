#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    ll a, b, c;
    cin >> a >> b >> c;
    
    ll d = c - a - b;
    if ( d > 0 && 4 * a * b < d * d) cout << "Yes" << endl;
    else cout << "No" << endl;

}