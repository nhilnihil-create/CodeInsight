#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    double v[n];
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v, v+sizeof(v)/sizeof(v[0]));
    double kachi = 0;
    kachi += v[0]/pow(2,n-1);
    for (int i=1; i<n; i++) {
        kachi += v[i]/pow(2,n-i);
    }
    cout << kachi << endl;
}