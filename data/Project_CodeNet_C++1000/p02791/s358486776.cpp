#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int p[n];
    for (int i=0; i<n; i++){
        cin >> p[i];
    }
    int m = p[0];
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (m >= p[i]) cnt++;
        m = min(m, p[i]);
    }
    cout << cnt << endl;
}