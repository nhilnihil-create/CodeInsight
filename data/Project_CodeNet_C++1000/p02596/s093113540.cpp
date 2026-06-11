#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;
using ll = int64_t;

int main(){
    int k; cin >> k;
    if(k%2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    int a[1000001] = {0};
    a[1] = 7%k;
    for(int i = 2; i <= k; i++) a[i] = (10*a[i-1] + 7)%k;

    for(int i = 1; i <= k; i++) {
        if(a[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}