#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);

    for(int i=0; i<k; i++) {
        int d;
        cin >> d;
        vector<int> b(d);
        for(int j=0; j<d; j++) {
            cin >> b[j];
            a[b[j]-1] = 1;
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        if(a[i] == 0) ans++;
    }

    cout << ans << endl;
}