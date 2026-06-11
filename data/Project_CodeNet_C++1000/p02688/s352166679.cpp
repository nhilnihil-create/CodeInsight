#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int n; cin >> n;
    int k; cin >> k;
    vector<int> sweet(k);
    vector<vector<int>> holder(k);
    int a;
    rep(i, k){
        cin >> sweet.at(i);
        rep(j, sweet.at(i)){
            cin >> a;
            holder.at(i).push_back(a);
        }
    }

    int ans = 0;
    bool have = false;
    for(int person = 1; person<=n; person++){
        have = false;
        rep(j, k){
            rep(search, sweet.at(j)){
                if(holder.at(j).at(search) == person){
                    have = true;
                }
            }
        }
        if(!have) ans++;  
    }

    cout << ans << endl;

    return 0;
}