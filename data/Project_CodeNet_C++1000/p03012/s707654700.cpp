#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int w[n], ruikei[n];
    cin >> w[0];
    ruikei[0] = w[0];
    for (int i=1; i<n; i++) {
        cin >> w[i];
        ruikei[i] = ruikei[i-1]+w[i];
    }
    int result = ruikei[n-1];
    for (int i=0; i<n-1; i++) {
        result = min(abs(ruikei[n-1]-2*ruikei[i]), result);
    }
    cout << result << endl;
}