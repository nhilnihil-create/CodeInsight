#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

int n;
string l;
v2<int> dp;

const int MOD = 1e9+7;

int f(int index, bool edge){
    if(index==n) return 1;
    if(dp[index][edge] != -1) return dp[index][edge];

    if(edge){
        if(l[index]=='0'){
            dp[index][edge] = f(index+1, true);
        }
        else{
            dp[index][edge] = (2LL*f(index+1, true) + f(index+1, false))%MOD;
        }
    }
    else{
        dp[index][edge] = (3LL*f(index+1, false))%MOD;
    }

    return dp[index][edge];
}

void solve(){
    cin >> l;
    n = l.length();
    dp = fill(n, 2, -1);
    int ans = 0;
    if(l[0]=='0'){
        ans = f(1, true);
    }
    else{
        ans = (2LL*f(1, true) + f(1, false))%MOD;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}