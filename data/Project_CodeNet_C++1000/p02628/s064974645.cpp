#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector p(n,0);
    for (int i=0; i<n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    k = min(n,k);
    int ans = accumulate(p.begin(), p.begin()+k, 0);
    cout << ans << endl;
}
