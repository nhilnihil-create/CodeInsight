#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long int> s(n);
    s[0] = a[0];

    long int result = 0;
    long int temp = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] < s[i - 1]) {
            temp = s[i - 1] - a[i];
            result += temp;
            s[i] = a[i] + temp;
        } else {
            s[i] = a[i];
        }
    }

    cout << result << endl;

    return 0;
}