#include<iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int ans = 1;
    long long t = k;
    while(n >= t) {
        ans++;
        t *= k;
    }

    cout << ans << endl;
    
}