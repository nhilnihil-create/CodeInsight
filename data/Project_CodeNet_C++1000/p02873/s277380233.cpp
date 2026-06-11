#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    int n = s.size();
    vector<int> res(n + 1);
    int p = 1;
    rep(i, n){
        if (s[i] == '<'){
            res[i + 1] = p;
            p++;
        }else{
            p = 1;
        }
    }
    p = 1;
    for (int i = n - 1; i >= 0; i--){
        if (s[i] == '>'){
            res[i] = max(p, res[i]);
            p++;
        }else p = 1;
    }
    ll ans = 0;
    rep(i, n + 1) ans += (ll)res[i];
    cout << ans << endl;
}
