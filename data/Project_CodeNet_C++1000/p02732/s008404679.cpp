#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
    
using namespace std;
using ll = long long;
using pii = pair<int, int>;
    
const int oo = 1e9 + 7;
const int mod = 1e9 + 7, maxn = 200200;
const double PI = acos(-1);

int main(){

    ll n, sum = 0;

    cin >> n;

    vector<ll> v(n), freq(n+1, 0);

    for (int i=0; i<n; i++){
        cin >> v[i];
        freq[v[i]]++;
    }

    for (int i=1; i<=n; i++){
        sum += (freq[i]*(freq[i] - 1))/2;
    }

    for (int i=1; i<=n; i++){
        ll val = (freq[i]*(freq[i] - 1))/2, next = ((freq[i] - 2)*(freq[i] - 1))/2;
        next = max(0LL, next);
        freq[i] = sum - val + next;
    }

    for (int i=0; i<n; i++){
        cout << freq[v[i]] << endl;
    }
    return 0;
}