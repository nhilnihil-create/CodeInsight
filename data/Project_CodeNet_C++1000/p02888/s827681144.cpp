#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    a[n] = 1e4;
    
    sort(a.begin(),a.end());
    
    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(j+1 > n-1) break;

            int l = j;
            int r = n;

            while(l < r -1){
                int m = l + (r-l)/2;
                if(a[i] + a[j] > a[m]) l = m;
                else r = m;
            }

            ans += l-j;

        }
    }
    cout << ans << endl;

}