#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    std::ios::sync_with_stdio(false);
    ll a;
    double b;
    cin >> a >> b;
    ll B;
    B = b * 100 + 0.5;
    cout << (ll)(a * B) / 100 << endl;
    return 0;
}
