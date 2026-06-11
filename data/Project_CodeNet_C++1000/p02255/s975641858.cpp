#include <iostream>
using namespace std;

int main(void) {
    int a[1000] = {};
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i; j > 0; --j) {
            if(a[j] < a[j - 1]) {
                int copy = a[j];
                a[j] = a[j - 1];
                a[j - 1] = copy;
            }
        }
        cout << a[0];
        for(int j = 1; j < n; ++j) {
            cout << ' ' << a[j];
        }
        cout << endl;
    }
}
