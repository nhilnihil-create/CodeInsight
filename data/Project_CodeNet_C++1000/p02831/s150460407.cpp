#include <bits/stdc++.h>
using namespace std;
#define ll long long

void gcd(int a, int b)
{
    if ( a % b == 0)
        return;

    return gcd(b, a % b);
}

int main() { 
    ll A, B;
    cin >> A >> B;

    cout << A * B / gcd(A, B) << endl;
}