#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if ( a % b == 0)
        return b;

    return gcd( b, a % b );
}

int main()
{
    int N;
    cin >> N;

    long long ans = 0;
    N++;
    for (int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            for(int k = 1; k < N;k++) {
                int a = gcd(max(i,j), min(i,j));
                ans += gcd(max(a,k), min(a,k));
            }
        }
    }
    cout << ans << endl;
}