	#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e6 + 5;

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        ll a[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
        ll k;
        cin >> k;
        cout << a[k - 1];
}
