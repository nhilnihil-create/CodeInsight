#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string S;
    cin >> S;
    ll K;
    cin >> K;
    ll len = S.size();
    ll sub_count = 0;
    ll count = 0;
    rep(i,len - 1){
        if (S[i] == S[i + 1]){
            sub_count++;
            if (sub_count % 2 == 1){
                count++;
            }
        }
        else{
            sub_count = 0;
        }
    }
    ll count_net = 1;
    ll ans = 0;
    rep(i,len - 1){
        if (S[0] == S[i + 1]) count_net++;
    }
    if (count_net == len){
        ans = (len * K) / 2;
    }
    else if (S[0] != S[len - 1]){
        ans = count * K;
    }
    else{
        ll cnt1 = 1;
        while(cnt1 < len){
            if (S[cnt1 - 1] != S[cnt1]){
                break;
            }
            else cnt1++;
        }
        ll cnt2 = 1;
        while(cnt2 < len){
            if (S[len - cnt2 - 1] != S[len - cnt2]){
                break;
            }
            else cnt2++;
        }
        ans =  count * K + ((cnt1 + cnt2) / 2) * (K - 1) - (cnt1 / 2) * (K - 1) - (cnt2 / 2) * (K - 1);
    }
    cout << ans << endl;
}
