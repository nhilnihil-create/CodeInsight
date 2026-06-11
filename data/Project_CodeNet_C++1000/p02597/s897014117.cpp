#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void){
    int N;
    string C;
    cin >> N >> C;
    int w=0, r=0;
    rep(i, N) if(C.at(i) == 'R') r++;
    int ans = max(w, r);

    for(int i=0;i<N;i++){
        if(C.at(i) == 'W') w++;
        else r--;
        ans = min(ans, max(w, r));
    }

    cout << ans << endl;

    return 0;
}