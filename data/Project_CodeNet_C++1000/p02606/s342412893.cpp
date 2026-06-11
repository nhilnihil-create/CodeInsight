#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int L, R, d;
    cin >> L >> R >> d;
    int ans = 0;
    for(int i = L; i <= R; i++){
        if(i%d == 0) ans++;
    }

    cout << ans << endl;
    return 0;
}