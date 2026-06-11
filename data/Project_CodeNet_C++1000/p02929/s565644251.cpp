#include <bits/stdc++.h>

#include <math.h>
#include <stdlib.h>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true; } return false; }

//INT_MAX	2,147,483,647 = 2*1.0e9

const ll mod = 1e9 + 7;

int main(){
    ll N; cin >> N;

    string S; cin >> S;

    int len = S.length();

    if(S[0] == 'W' || S[len-1] =='W'){
        cout << 0 <<endl;
        return 0;
    }

    vector<int> SE;
    SE.push_back(0);
    for(int i = 1; i < len; i++){
        if(i%2 == 1 && S[i] == 'W') {
            SE.push_back(0);
        } else if(i%2 == 0 && S[i] == 'B') {
            SE.push_back(0);
        } else {
            SE.push_back(1);
        }
    }

    ll ans = 1;
    ll sum = 0;
    for(int i = 0; i < len; i++){
        // Start側ならsumを足す
        if(SE[i] == 0) sum++;
        // End側なら持っている選択肢の数をansにかけて、選択肢を一つ減らす
        else {
            ans *= sum;
            ans %= mod;
            sum--;
        }
    }

    if(sum != 0) {
        cout << 0 <<endl;
        return 0;
    }

    for(ll i = 1; i <=N; i++){
        ans *= i;
        ans %= mod;
    }
    
    cout << ans << endl;

    return 0;
}
