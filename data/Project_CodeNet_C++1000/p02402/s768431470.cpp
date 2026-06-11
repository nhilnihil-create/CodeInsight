#include <iostream>

using namespace std;

int main() {
    long int n, max = 0, min = 0, sum = 0;
    long int *a = new long int[n];
    
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            min = a[i];
            max = a[i];
            sum = a[i];
        } else {
            if(a[i] < min) min = a[i];
            if(a[i] > max) max = a[i];
            
            sum += a[i];
        }
    }
    cout << min << " " << max << " " << sum << endl;
}