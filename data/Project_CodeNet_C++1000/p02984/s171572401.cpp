#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n;
    cin >> n;
    int arr[n + 5];
    ll x, ans, start = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i % 2 == 0) start += arr[i];
        else start -= arr[i];
    }
    x = start, ans = 0;
    cout << start << " ";
    for(int i = 1; i < n; i++){
        ans = 2 * arr[i - 1] - x;
        x = ans;
        cout << ans << " ";
    }
    return 0;
}
