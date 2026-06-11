#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n; 

    int prod = 1;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i=0; i<n; i++){
        if(log10(prod) + log10(a[i]) >= 18.01){
            cout << -1 << endl;
            return 0;
        }
        else if(prod * a[i] > 1000000000000000000){
            cout << -1 << endl;
            return 0;
        }
        else{
            prod *= a[i];
        }
    }
    cout << prod << endl;

    return 0;
}