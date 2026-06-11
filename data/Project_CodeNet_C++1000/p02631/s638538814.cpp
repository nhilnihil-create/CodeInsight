#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll allxor = 0;
    for (int i=0;i<n;i++)
        cin >> arr[i], allxor ^= arr[i];
    
    for (int i=0;i<n;i++)
        cout << (ll)(arr[i] ^ allxor) << " ";
    cout << "\n";
}