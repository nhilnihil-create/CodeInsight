#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define int long long
    
    int n, k;
    cin >> n >> k;
    
    vector <int> prefix_sums(200005, 0);
    
    for (int i=1; i<=200003; i++){
        prefix_sums[i] = prefix_sums[i-1] + i;
        //if (prefix_sums[i] >= MOD) prefix_sums[i] -= MOD;
    }
    
    //for (int i=0; i<=100; i++) cout << prefix_sums[i] << endl;
    
    int ans = 0;
    for (int i=k; i<=n+1; i++){
        int minimum_sum = prefix_sums[i-1];
        int maximum_sum;
        if (i != n+1)
        maximum_sum = prefix_sums[n] - prefix_sums[n-i];
        else maximum_sum = prefix_sums[n];
        ans =  ans + (maximum_sum - minimum_sum + 1);
        if (ans >= MOD) ans %= MOD;
    }
    
    cout << ans << endl;
}