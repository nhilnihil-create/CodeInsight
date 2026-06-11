// printing all coordinates that cointain a stone painted black in ascending order
#include<bits/stdc++.h>
using namespace std;

int K, X;

int main() {
    cin >> K >> X;
    int ans = X-K+1;
    while (ans != X+K) {
        cout << ans << " ";
        ans++;
    }
    cout << endl;
    return 0;
}
