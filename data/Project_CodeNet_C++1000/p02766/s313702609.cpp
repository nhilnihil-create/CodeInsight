#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    while(true) {
        if(n/k > 0) {
            n = n / k;
            ans++;
        }
        else break;
    }
    cout << ans+1 << endl;
}