#include<iostream>
#include<vector>
using namespace std;
#define MAX 80

int main() {
    int n;
    long long s, m = 1000;
    vector<int> a(MAX+10);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int mini = 300;
    for (int i = 0; i < n; i++) {
        mini = min(a[i], mini);
        if (a[i] > mini) {
            s = m / mini;
            m += (a[i] - mini) * s;
            mini = a[i];
        }
    }
    cout << m << endl;
}