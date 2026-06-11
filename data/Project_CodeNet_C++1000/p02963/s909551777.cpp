#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

ll s;

int main()
{
    cin >> s;
    cout << "0 0 1000000000 1 ";
    const ll m = 1e9;
    int x = (m - s % m) % m;
    int y = (s + x) / m;
    cout << x << " " << y;
    return 0;
}