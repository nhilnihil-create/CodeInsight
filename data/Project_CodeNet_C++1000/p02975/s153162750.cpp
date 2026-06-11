#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
    int N;
    cin >> N;
    int bit = 0;
    rep(i, N) {
        int a; cin >> a;
        bit ^= a;
    }
    
    string ans = "No";
    if(bit == 0) ans = "Yes";
    cout << ans << endl;
}
