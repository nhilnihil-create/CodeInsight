#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a.at(i);
    
    int ans = 0;
    rep(i, N){
        if(i%2 == 0 && a.at(i)%2 == 1) ans++;
    }
    cout << ans << endl;
}
