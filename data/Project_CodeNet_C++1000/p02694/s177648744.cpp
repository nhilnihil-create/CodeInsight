#include<iostream>
using namespace std;


int main() {
    long long X, depo = 100;
    cin >> X;


    int ans = 0;
    while(X > depo) {
        depo += depo / 100;
        ans++;
    }

    cout << ans << endl;
}