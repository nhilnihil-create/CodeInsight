#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int min;
    cin >> min;
    int res = 1;
    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;
        if (min > temp) {
            min = temp;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
