#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    long double n, k; cin >> n >> k;
    vector<long double> p(n);
    for(int i=0; i<n; ++i){cin >> p[i];}
    for(int i=0; i<n; ++i){p[i] = (p[i]+1)/2;}

    vector<long double> sum(n, 0); 
    for(int i=0; i<n+1; ++i){
        sum[i+1] = sum[i]+p[i]; 
    }
    
    long double res = 0;
    for(int i=0; i<n-k+1; ++i){
        res = max(res, sum[i+k]-sum[i]);
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}