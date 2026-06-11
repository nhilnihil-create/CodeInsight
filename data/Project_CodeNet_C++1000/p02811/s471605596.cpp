#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define yorn(f) cout << ((f) ? "Yes" : "No") << endl
#define YORN(f) cout << ((f) ? "YES" : "NO") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    int K, X;
    cin >> K >> X;
    yorn(K * 500 >= X);
    return 0;
}