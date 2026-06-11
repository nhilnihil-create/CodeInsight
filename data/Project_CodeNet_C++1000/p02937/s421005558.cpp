#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;


int main(){
    string s, t;
    cin >> s >> t;
    const ll mod = s.size();
    vector<int> n[26];
    rep(i, s.size()){
        int num = s[i] - 'a';
        n[num].push_back(i);
    }
    rep(i, 26){
        if(n[i].size() == 0) continue;
        n[i].push_back(n[i][0] + mod);
    }
    ll ans = -1;
    rep(i, t.size()){
        if(n[t[i]-'a'].size() == 0){
            cout << "-1" << endl;
            return 0;
        }
        int num = t[i] - 'a';
        ll idx = ans % mod;
        auto itr = upper_bound(n[num].begin(), n[num].end(), idx);
        ans = (ans / mod) * mod + *itr;
        // cout << num << " " << *itr << endl;
        // cout << ans << endl;
    }
    // rep(i, 26){
    //     bool a = false;
    //     rep(j, n[i].size()){
    //         if(j == 0) cout << i + 1 << ";";
    //         cout << n[i][j] << " ";
    //         a = true;
    //     }
    //     if(a) cout << endl;
    // }
    cout << ans + 1 << endl;
}