#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll x;
    cin >> x;
    while (1) {
        bool flag = true;
        ll y = x;
        for (int i = 2; i * i <= y; i++) 
            if (y%i == 0)
                flag = false;

        if (flag) {
            cout << x << endl;
            return 0;
        }
        x++;
    }
}