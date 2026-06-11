#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N;
    cin >> N;
    int ans = 1000-N%1000;
    if (N%1000==0) {
        ans = 0;
    }
    cout << ans << endl;
}