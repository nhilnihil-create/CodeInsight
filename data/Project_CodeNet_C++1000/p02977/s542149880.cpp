#include <iostream>

using namespace std;
typedef long long ll;

void out(ll i, ll j){ cout << i << " " << j << endl; }

int main(){
    ll n;
    cin >> n;

    if((n & (n - 1)) == 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    ll n2 = n - (1 - n % 2);
    out(1, n + 2);
    out(n + 2, n + 3);
    out(n + 3, n + 1);
    out(n + 1, 2);
    out(2, 3);
    for(ll i = 3; i < n2; i+=2){
        out(n + 1, i + 1);
        out(i + 1, i + 2);
        out(n + 1, n + i + 2);
        out(n + i + 2, n + i + 1);
    }
    if(n % 2 == 0){
        ll x = n ^ (n - 1) ^ 1;
        out(n + n - 1, n + n);
        out(x, n);
    }
    return 0;
}
