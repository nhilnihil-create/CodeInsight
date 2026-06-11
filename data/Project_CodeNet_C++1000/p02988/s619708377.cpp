#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n, ans = 0;
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n - 1; i++){
        if((arr[i] > arr[i - 1] && arr[i] < arr[i + 1]) ||
           (arr[i] < arr[i - 1] && arr[i] > arr[i + 1]))
            ans++;
    }
    cout << ans;
    return 0;
}
