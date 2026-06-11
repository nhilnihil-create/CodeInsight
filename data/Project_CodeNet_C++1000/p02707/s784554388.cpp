#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;  cin >> n;
    vector<int> v(n,0);
    for (int i = 0; i < n-1; i++) {
        int p;  cin >> p;
        v[p-1]++;
    }

    for (int i = 0; i < n; i++)
        cout << v[i] << endl;

    return 0;
}