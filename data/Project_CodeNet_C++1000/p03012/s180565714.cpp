#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n;
    cin >> n;
    int arr[n + 5], ans = 1e9;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++){
        int sum1 = 0, sum2 = 0;
        for(int j = 0; j < i; j++)
            sum1 += arr[j];
        for(int j = i; j < n; j++)
            sum2 += arr[j];
        ans = min(ans, abs(sum1 - sum2));
    }
    cout << ans;
    return 0;
}
