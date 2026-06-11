#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main (){
    int X;
    cin >> X;

    vector<bool> dp(X+200,false);
    vector<int> a = {100,101,102,103,104,105};

    dp[0] = true;

    rep(i,0,X+1) {
        if (!dp[i]) {
            continue;
        }
        rep(j,0,a.size()) {
            dp[i+a[j]] = true;
        }
    }

    cout << dp[X] << endl;

}



