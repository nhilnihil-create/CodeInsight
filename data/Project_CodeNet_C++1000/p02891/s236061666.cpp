#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

string S;
ll K;

signed main(){
    cin >> S >> K;

    if(S[0] == S.back() && K > 1){
        bool flg = true;
        rep(i, S.size()-1) flg &= (S[i] == S[i+1]);
        if(flg){
            cout << S.size()*K/2 << endl;
            exit(0);
        }

        ll ans = 0;
        ll cnt = 1;
        for(int i=1; i<S.size(); i++){
            if(S[i-1] == S[i]) cnt++;
            else{
                ans += cnt/2;
                cnt = 1;
            }
        }
        ans += cnt/2;

        S = S.substr(S.size()-cnt, cnt) + S.substr(0, S.size()-cnt);
        ll ans2 = 0;
        cnt = 1;
        for(int i=1; i<S.size(); i++){
            if(S[i-1] == S[i]) cnt++;
            else{
                ans2 += cnt/2;
                cnt = 1;
            }
        }
        ans2 += cnt/2;

        cout << ans + ans2 * (K-1) << endl;
    }
    else{
        ll ans = 0;
        ll cnt = 1;
        for(int i=1; i<S.size(); i++){
            if(S[i-1] == S[i]) cnt++;
            else{
                ans += cnt/2;
                cnt = 1;
            }
        }
        ans += cnt/2;
        cout << ans * K << endl;
    }
}