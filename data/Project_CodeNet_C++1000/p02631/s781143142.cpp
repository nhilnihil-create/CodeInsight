#include<bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

using ll = long long;
const int N = 2e5+5;

vector<ll> a(N),l(N),r(N);
int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        l[i] = l[i-1]^a[i];
    for(int i = n; i >= 1; --i)
        r[i] = r[i+1]^a[i];
  
    for(int i = 1; i <= n; ++i)
        cout << (l[i-1] ^ r[i+1]) << ' ';
    return 0;
}
