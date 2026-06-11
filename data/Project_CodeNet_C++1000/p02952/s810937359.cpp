#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    int cnt = 1, ans = 0;
    while(cnt <= n){
        if(to_string(cnt).size() % 2 == 1) ans++;
        cnt++;
    }
    cout << ans << endl;
    return 0;
}