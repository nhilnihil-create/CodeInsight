#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<vector<ll> > vec_group(10,vector<ll>(10));
    for (ll i = 1; i <= N; i++){
        int start;
        int goal;
        goal = i % 10;
        if (i < 10) start = i;
        else if (i < 100) start = i / 10;
        else if (i < 1000) start = i / 100;
        else if (i < 10000) start = i / 1000;
        else if (i < 100000) start = i / 10000;
        else start = i / 100000;
        
        if (goal != 0){
            vec_group[start][goal]++;
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= 9; i++){
        for (ll j = 1; j <= 9; j++){
            ans += vec_group[i][j] * vec_group[j][i];
        }
    }
    cout << ans << endl;
}
