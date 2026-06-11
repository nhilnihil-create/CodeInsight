#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int N;
    cin >> N;
    int count = 0;
    while(N > 0) {
        int x = log10(N);
        if(x % 2 == 0) {
            ans++;
        }
        N--;
    }

    cout << ans << endl;
}