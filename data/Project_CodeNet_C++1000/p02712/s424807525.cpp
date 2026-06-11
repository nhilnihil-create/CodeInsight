#include <bits/stdc++.h>
using namespace std;

vector<int> a(10000000);
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        a[i] = i+1;
    }

    long long ans = 0;
    for(int i=0; i<n; i++) {
        if( a[i] % 3 == 0 || a[i] % 5 == 0) {
            a[i] = 0;
            continue;
        }
        ans += a[i];
    }

    cout << ans << endl;
}