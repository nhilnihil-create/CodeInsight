#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a, b, c;

    cin >> a >> b >> c;

    int n = c - (a - b);

    if (n > 0)
    {
    	cout << n;
    }   
    else {
    	cout << 0;
    }

    return 0;
}