#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

int main()
{
    ll S;
    cin >> S;

    cout << "0 " << "0 " << "1000000000 " << "1 " << (((int)1e9) - S%((int)1e9))%((int)1e9) << ' ' << (S-1)/((int)1e9)+1 << endl;

    return 0;
}