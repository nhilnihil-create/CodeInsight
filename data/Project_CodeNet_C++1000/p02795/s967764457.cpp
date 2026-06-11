#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll H, W, N;
    cin >> H >> W >> N;
    cout << (N + (max(H, W) - 1)) / max(H, W) << endl;
}
