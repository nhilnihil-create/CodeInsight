#include <bits/stdc++.h>

using namespace std;

void solve(){
    int k, x;
    cin >> k >> x;
    for (int stone = x-k+1; stone <= x+k-1; stone++){
        cout << stone << ' ';
    }
    cout << '\n';
}

int main(){
    //int t; cin >> t; while(t--)
        solve();
}