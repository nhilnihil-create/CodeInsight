#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<ll> ans;

    ll cnt = 0;

    ll l;
    ll r = N;
    bool check;
    while(r != 0){
        check = false;
        l = max(r - M, zero);
        for (; l < r; l++) {
            if(S[l] == '0'){
                ans.push_back(r - l);
                r = l;
                check = true;
                break;
            }
        }
        if(check == true){
            cnt++;
        }
        else{
            printf("-1\n");
            return 0;
        }

    }
    for (ll i = cnt - 1; i >= 0; i--) {
        printf("%lld ", ans[i]);
    }


}