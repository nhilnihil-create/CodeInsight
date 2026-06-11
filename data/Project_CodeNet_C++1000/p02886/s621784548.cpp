#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];
    int ans = 0;

    int j = 0;
    for(int i = 0; i < n; i++){
        if( i <= j ) continue;
        else if( j == i ) continue;
        else ans += d[j] * d[i];
        if( i == n-1 ) {
            j++;
            i = j;
        }
    }

    cout << ans << endl;
}