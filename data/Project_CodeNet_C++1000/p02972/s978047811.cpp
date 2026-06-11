/**
*    author:  souzai32
*    created: 14.08.2020 15:16:03
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a.at(i);
    vector<int> ans;

    for(int i=n; i>0; i--){
        if(a.at(i)%2){
            ans.push_back(i);
            for(long long j=1; j*j<=i; j++){
                if(i%j==0){
                    a.at(j)++;
                    if(j*j!=i) a.at(i/j)++;
                }
            }
        }
        // rep(j,ans.size()-1) cout << ans.at(j) << ' ';
        // cout << endl;
    }
    cout << ans.size() << endl;
    reverse(ans.begin(),ans.end());
    rep(i,ans.size()-1) cout << ans.at(i) << ' ';
    if(ans.size()) cout << ans.at(ans.size()-1) << endl;

    return 0;
}