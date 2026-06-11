#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    ll tot = 0;
    vector<int> dp(2), p(2);
    dp.at(0) = 0;
    dp.at(1) = 1;
    rep(i,s.size()){
        char c  = s.at(i);
        int d = atoi(&c);
        swap(p,dp);
        dp.at(0) = min(p.at(0)+d,p.at(1)+(10-d));
        if(d==9){
            dp.at(1) = p.at(1);
        }else {
            dp.at(1) = min(p.at(0)+d+1, p.at(1)+(10-d-1));
        }
    }
    ll res = min(dp.at(0),dp.at(1)+1);
    cout << res << endl;
    return 0;
}