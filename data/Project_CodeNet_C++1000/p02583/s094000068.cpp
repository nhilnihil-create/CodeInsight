#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n, *l;
    cin >> n;
    l = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> l[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (l[i] != l[j] && l[j] != l[k] && l[k] != l[i] && max(l[i]-l[j], l[j]-l[i]) < l[k] && l[k] < l[i] + l[j])
                    ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}