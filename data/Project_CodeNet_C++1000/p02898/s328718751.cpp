#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
int arr[N];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k, cnt =0;
    cin >> n >> k;
    for(int i =0 ; i < n; ++i){
        cin >> arr[i];
        if(arr[i] >= k)
            cnt++;
    }
    cout << cnt;
}