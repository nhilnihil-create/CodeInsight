#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int k, n;
    cin >> k >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = k - arr[n - 1] + arr[0];
    for(int i = 1; i < n; i++)
        mx = max(mx, arr[i] - arr[i - 1]);
    cout << k - mx;
    return 0;
}