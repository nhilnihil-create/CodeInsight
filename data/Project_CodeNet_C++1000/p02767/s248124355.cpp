#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    int ans = 99999999;
    for(int i=mn; i<=mx; ++i){
        int st=0; 
        for(int j=0; j<n; ++j){
            st += (a[j]-i) * (a[j]-i);
        }
        ans = min(ans, st);
    }
    cout << ans;
    return 0;
}
