#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#define all(x) x.begin(), x.end()
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#define sorn(i, n) char((i == n-1)?'\n':' ')
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;

int main(){
    ll n; cin >> n;

    vector<int> info;
    while(n > 0) {
        int digit = n%26;
        info.push_back(digit-1);
        n /= 26;
    }

    rep(i, info.size() - 1) {
        if(info[i] < 0) {
            info[i] += 26;
            info[i+1]--;
        }
    }
    if(info[info.size() - 1] < 0) info.pop_back();
    reverse(all(info));

    string ans = "";
    for(int i : info) {
        ans += 'a' + i;
    }
    cout << ans << endl;

    return 0;
}