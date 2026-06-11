#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 0;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i % 2 == 0 && a[i] % 2 == 1) ans += 1;
    }
    cout << ans << endl;
    return 0;
}