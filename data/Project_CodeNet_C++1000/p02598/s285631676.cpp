#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int l = 1;
    int r = 1000000000;
    for(int i=0; i<n; i++) cin >> a[i];

    while(l < r){
        int m = l + (r-l)/2;
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt += (a[i]-1)/m;
        }
        if(cnt > k) l = m + 1;
        else r = m;
        //cout << l << " " << r << endl;
    }
    cout << r << endl;
}