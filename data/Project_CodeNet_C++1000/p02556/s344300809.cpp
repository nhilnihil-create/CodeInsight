#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    int max_w, max_z, min_w, min_z;
    int x, y, w, z;
    cin >> x >> y;
    w = x - y;
    z = x + y;
    min_w = w;
    max_w = w;
    min_z = z;
    max_z = z;
    for(int i=1;i<N;i++){
        cin >> x >> y;
        w = x - y;
        z = x + y;
        min_w = min(w, min_w);
        max_w = max(w, max_w);
        min_z = min(z, min_z);
        max_z = max(z, max_z);
    }
    cout << max(max_z - min_z, max_w - min_w) << endl;

    return 0;
}