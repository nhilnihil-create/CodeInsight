#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> p(n), q(n), v(n);
    for(int i=0; i<n; i++) cin >> p[i];
    for(int i=0; i<n; i++) cin >> q[i];
    for(int i=0; i<n; i++) v[i] = i + 1;
    int a = -1, b = -1, k = 0;
    while(next_permutation(v.begin(), v.end())) {
        bool ok1 = true, ok2 = true;
        for(int i=0; i<n; i++) {
            if(p[i] != v[i]) ok1 = false;
            if(q[i] != v[i]) ok2 = false;
        }
        if(ok1) a = k;
        if(ok2) b = k;
        if(a != -1 && b != -1) break;
        k++;
    }
    cout << abs(a - b) << endl;
}