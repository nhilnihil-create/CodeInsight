#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    cin >> N;
    ll ans = 0;
    vector<string> sss(N);
    rep(i, N){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        sss[i] = s;
    }
    sort(sss.begin(), sss.end());
    ll cnt = 0;
    rep(i, N-1){
        if(sss[i]==sss[i+1]) cnt++;
        else{
            if(cnt>0) ans+=cnt*(cnt+1)/2;
            cnt = 0;
        }
    }
    if(cnt!=0) ans+=cnt*(cnt+1)/2;
    cout << ans << endl;
    return 0;
}
