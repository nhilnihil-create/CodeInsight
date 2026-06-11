#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,d,ans = 0;
    cin >> n >> d;
    int x,y;
    
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        if(sqrt(pow(x, 2) + pow(y, 2)) <= d) {
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}