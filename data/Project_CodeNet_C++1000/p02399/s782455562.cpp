#include <bits/stdc++.h>
using namespace std;

int main() {
    long a, b;
    cin >> a >> b;
    
    cout << a / b << " " << a % b << " " << fixed << setprecision(5) << ((double) a) / ((double) b) << endl;
    
    return 0;
}
