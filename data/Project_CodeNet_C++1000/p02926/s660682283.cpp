#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[105], y[105];


int main(){    
    int n; cin >> n;
    vector< pair<double,int> > vec;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        vec.push_back({atan2(y[i], x[i]), i});
    }
    sort(vec.begin(), vec.end());

    ll res = -1e18;    
    for(int i = 0; i < n; i++){
        ll xx = 0, yy = 0;
        for(int j = 0; j < n; j++){
            int idx = (i+j)%n;
            idx = vec[idx].second;
            xx += x[idx], yy += y[idx];
            res = max(res, xx*xx + yy*yy);
        }
    }
    printf("%.10f\n", sqrt(res));
    return 0;
}