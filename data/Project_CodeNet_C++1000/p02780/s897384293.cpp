#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++){
        cin >> p.at(i);
    }

    vector<long long> p_sum(n);
    p_sum[0]=p[0];
    for (int i = 1; i < n; i++){
        p_sum[i]=p_sum[i-1]+p[i];
    }

    long long maxp_sum=p_sum[k-1];
    for (int i = 0; i < n-k; i++){
        maxp_sum=max(maxp_sum,p_sum[k+i]-p_sum[i]);
    }
    double ans=0.5*(double)k+(double)maxp_sum/2.0;

    cout << fixed << setprecision(13) << ans << endl;
}
