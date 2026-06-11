#include <bits/stdc++.h>
#define rep(i,d) for (int i = 0; i < (d); i++);
using namespace std;
using ll = long long;


int main() {
    int n,d; cin >> n >> d;

    if (n <= (2*d + 1)) {
        cout << "1" << endl;
    }

    if (n > (2*d + 1)){
        if (n % (2*d + 1) == 0){
            cout << n / (2*d + 1) << endl;
        }
        if (n % (2*d + 1) != 0){
            cout << (n / (2*d + 1)) + 1 << endl;
        }
    }
}