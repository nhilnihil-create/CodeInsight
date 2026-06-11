#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    
    vector<long long> p(n);
    for (int i = 0; i < n; i++){
        cin >> p.at(i);
    }

    vector<long long> p_sum(n-k+1,0);
    for (int i = 0; i < k; i++){
        p_sum[0]=p_sum[0]+p[i];
    }
    for (int i = 1; i < n-k+1; i++){
        p_sum[i]=p_sum[i-1]-p[i-1]+p[i-1+k];
    }

    long long maxp_sum=0;
    for (int i = 0; i < n-k+1; i++){
        maxp_sum=max(maxp_sum,p_sum[i]);
    }
    double ans=0.5*(double)k+(double)maxp_sum/2.0;

    cout << fixed << setprecision(13) << ans << endl;
}
