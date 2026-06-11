#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<ll> ans(0);
    ll now = N;
    bool possible = true;
    while(now > M){
        ll next = 0;
        for (ll i = 1; i <= M; i++){
            if (S[now - i] == '0') next = i;
        }
        if (next == 0){
            possible = false;
            break;
        }
        now -= next;
        ans.push_back(next);
    }
    if (possible) ans.push_back(now);
    if (!possible) cout << -1 << endl;
    else{
        for (ll i = ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}