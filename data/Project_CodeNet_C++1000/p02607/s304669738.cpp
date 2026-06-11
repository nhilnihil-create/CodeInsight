#include <bits/stdc++.h>
#define ll long long
#define _ ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;

int main() { _
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i += 2){
        if(arr[i] % 2 == 1){
            ans++;
        }
    }
    cout << ans << endl;
}