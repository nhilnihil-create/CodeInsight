#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long ans = 0;

    if(n%2 == 0){
        n /= 2;
        while(n){
            ans += n/5;
            n /= 5;
        }
    }
    cout << ans << endl;
}
