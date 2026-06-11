#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    for(int i=1; i<10; ++i){
        for(int j=0; j<10; ++j){
            if(i*j==n){
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
