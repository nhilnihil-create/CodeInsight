#include <bits/stdc++.h>
using namespace std;

int main(void){
    int A, B, m;
    cin >> A >> B >> m;
    vector<int> a(A), b(B);
    for (int i=0; i<A; i++) cin >> a[i];
    for (int i=0; i<B; i++) cin >> b[i];
    int ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
    int x, y, c;
    for (int i=0; i<m; i++){
        cin >> x >> y >> c;
        ans = min(ans, (int)(a[x-1] + b[y-1] - c));
    }
    cout << ans << endl;
}