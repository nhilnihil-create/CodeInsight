#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << x << "\n";
#define debug2(x,y) cout << x << " " << y << "\n"
#define fi first
#define se second
#define pb push_back
#define ll long long 
const ll mod = 1e9+7;
const int MAX = 2e5+5;

int main() {
    int n; cin >> n;
    if(n % 2 == 1){
        cout << 0 << "\n";
        return 0;
    }
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    int mid = n / 2;
    int ans =  abs(arr[mid-1] - arr[mid]);
    cout << ans << "\n";
}




