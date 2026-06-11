#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
const long long mod = 1e9 + 7;

int n, k, s;
void solve() {
    int i = 0;
    for(i = 0; i < k; i++)
        cout << s << " ";
    for(i = k; i < n; i++) {
        if(s == 1e9) cout << 1 << " ";
        else cout << s + 1 << " ";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    //cin >> test;
    while(test--){
        int i = 0;
        cin >> n >> k >> s;
        solve();
    }

    return 0;
}
