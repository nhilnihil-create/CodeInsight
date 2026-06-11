#include <iostream>
#include <iomanip>

int main()
{
    using namespace std;
    
    int n, k;
    double prefix_sum[200001] = {0}, p[200000], ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        prefix_sum[i + 1] += ((p[i] + 1) / 2 + prefix_sum[i]);
    }
    for(int i = 0; i <= n - k; i++){
        ans = max(ans, prefix_sum[i + k] - prefix_sum[i]);
    }
    cout << fixed << setprecision(12) << ans << endl;
}
