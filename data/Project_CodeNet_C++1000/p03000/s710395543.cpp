#include <iostream>
using namespace std;
int n, x;

int main() {
    cin >> n >> x;
    int L[n];
    for (int i=0; i<n; i++){
        cin >> L[i];
    }
    int cnts=1, total=0;
    for (int i=0; i<n; i++) {
        total += L[i];
        if (total > x) break;
        cnts += 1;
    }
    cout << cnts;
    return 0;
}