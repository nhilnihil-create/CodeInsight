#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
    int n;
    cin >> n;
    v1 b(n-1);
    rep(i, n-1){
        cin >> b[i];
    }
    int ans = b[0];
    for(int i = 1; i<n-1;i++){
        ans += min(b[i], b[i-1]);
    }
    if(n >=2) ans += b[n-2];
    cout << ans << endl;
}
