#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (2147483647)
#define MOD (int)(998244353) 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 0; i < n; ++i) sum += arr[i];
    double step = 1.0/(4.0 * (double) m);
    for(int i = 0; i < m; ++i) {
        if((double)arr[i] < (step * (double) sum)) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}