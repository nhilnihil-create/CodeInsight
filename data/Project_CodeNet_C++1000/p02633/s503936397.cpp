#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long int x;
    cin >> x;

    long long int k = 1;
    while((x*k) % 360 != 0)
        k++;
        
    cout << k << endl;
    
    return 0;
}