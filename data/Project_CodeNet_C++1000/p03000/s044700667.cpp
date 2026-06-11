#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> L(n);
    for(int i=0; i<n; i++) cin >> L[i];
    vector<int> D = {0};
    int count = 1;

    for(int i=1; i<=n; i++ ) {
        D[i] = D[i-1]+L[i-1];
        if(D[i] <= x) count++;
    }
    cout << count << endl;
}