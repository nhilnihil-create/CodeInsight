#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string S;
    cin >> S;
    ll len = S.size();
    vector<ll> straight(len + 1);
    vector<ll> reverse(len + 1);
    straight[0] = 0;
    reverse[len] = 0;
    ll straight_count = 0;
    ll reverse_count = 0;
    ll ans = 0;
    rep(i,len){
        if (S[i] == '<'){
            straight_count++;
        }
        else{
            straight_count = 0;
        }
        straight[i + 1] = straight_count;
    }
    for (ll i = len - 1; i >= 0; i--){
        if (S[i] == '>'){
            reverse_count++;
        }
        else{
            reverse_count = 0;
        }
        reverse[i] = reverse_count;
    }
    rep(i,len + 1){
        ans += max(straight[i], reverse[i]);
    }
    cout << ans << endl;
}
