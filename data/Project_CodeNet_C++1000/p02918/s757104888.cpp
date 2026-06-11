#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, K, c, ans=0;
string S;

signed main(){
    cin >> N >> K >> S;
    for(int i=1;i<N;i++) {
        if(S[i]!=S[i-1]) c++;
        else ans++;
    }
    if(2*K>=c) {
        ans += c;
    }
    else {
        ans += 2*K;
    }
    cout << ans << endl;
    return 0;
}