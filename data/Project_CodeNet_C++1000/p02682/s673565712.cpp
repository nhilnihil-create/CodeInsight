#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    if(a >= k) {
        cout << k << '\n';
    } else if(a+b >= k && a < k) {
        cout << a << '\n';
    } else if(a+b+c >= k && a+b < k) {
        cout << a - (k-(a+b)) << '\n';
    } else {
        cout << a-b << '\n';
    }
}