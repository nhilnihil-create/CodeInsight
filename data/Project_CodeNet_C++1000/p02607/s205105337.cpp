#include <iostream>

using namespace std;

int main()
{
    int n, c, num;
    cin >> n;
    c = 0;
    for ( int i = 1; i <= n; i = i+2) {
        cin >> num;
        if ( num % 2 == 1) c++;
        if ( i != n) cin >> num;
    }
    cout << c;
}