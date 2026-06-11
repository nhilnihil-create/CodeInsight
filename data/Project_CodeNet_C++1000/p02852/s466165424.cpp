#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)


int main(){
    ll N, M;
    cin >> N >> M;

    char S[N + 2];
    cin >> S;

    ll p = N;
    ll t;
    stack<ll> ans;
    while(p > M){
        t = 0;
        for(ll i = M; i > 0; i--){
            if(S[p - i] == '0'){
                t = p - i;
                ans.push(i);

                break;
            }
        }
        if(t == 0){
            cout << -1 << endl;
            return 0;
        }
        p = t;
    }
    ans.push(p);

    ll steps = ans.size();
    rep(i, steps){
        if(i != 0){
            cout << " ";
        }
        cout << ans.top();
        ans.pop();
    }
    cout << endl;

    return 0;
}


