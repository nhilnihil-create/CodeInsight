#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;
    vector<ll> v(n, 0);
    ll temp = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        temp = temp ^ v[i];
    }


    for(int i = 0; i < n; i++) {
        cout << (temp ^ v[i]) << " ";
    }
    cout << endl;


    
    return 0;
}