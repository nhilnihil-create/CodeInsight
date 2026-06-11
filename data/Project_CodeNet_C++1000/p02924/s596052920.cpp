#include <bits/stdc++.h>

typedef long long ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define endl '\n'
const int N = 2e5 + 10;
using namespace std;

int main() {
    IO;
    ll n; cin>>n;
    --n;
    cout<<n*(n+1)/2;
}
