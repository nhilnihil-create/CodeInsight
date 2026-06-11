#include <bits/stdc++.h>
using namespace std;

int main(){
    int ap, a0, am, k;
    cin >> ap >> a0 >> am >> k;
    if ( a0 == 0 && am == 0) {
        cout << k << endl;
        return 0;
    }
    long long ans = 0;
    for(int i = 0; i<k; i++) {
        if( ap > 0 ) {
            ap--;
            ans++;
        }
        else if(a0 > 0 ) {
            a0--;
        }
        else {
            am--;
            ans--;
        }
    }

    cout << ans << endl;
}