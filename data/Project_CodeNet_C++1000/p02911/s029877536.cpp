#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    ll n, k, q;
    cin >> n >> k >> q;
    ll arr[q + 5], freq[n + 5] = {};
    for(int i = 0; i < q; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(k - q + freq[i] > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
