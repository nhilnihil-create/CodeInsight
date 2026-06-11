#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N+1);
    rep(i,N+1) {
        cin >> a[i];
    }
    
    vector<long int> d_max(N+1), d_min(N+1), max(N+1);
    bool tf = true;
    
    reverse(a.begin(), a.end());
    
    rep(i,N+1) {
        if(i == 0) {
            d_min[i] = a[0];
            d_max[i] = a[0];
        }
        else {
            d_min[i] = (d_min[i-1] + 1) / 2 + a[i];
            d_max[i] = d_max[i-1] + a[i];
        }
    }
    
    if(d_min[N] > 1)
        tf = false;
    
    reverse(d_max.begin(), d_max.end());
    reverse(a.begin(), a.end());
    
    //if(a[N] < 1)
        //tf = false;
    
    rep(i,N+1) {
        if(i == 0)
            max[i] = 1;
        else {
            max[i] = min((max[i-1] - a[i-1]) * 2, d_max[i]);
            //if(max[i] < max[i-1] - a[i-1])
                //tf = false;
        }
    }
    
    long int sum = 0;
    if(tf) {
        rep(i,N+1) {
            sum += max[i];
        }
    }
    else
        sum = -1;
    
    cout << sum << endl;
    
    return 0;
}
