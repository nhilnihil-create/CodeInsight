#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

const int MOD = 998244353;
inline int add(int a, int b){ return (a+b)%MOD; }
inline int sub(int a, int b){ return ((a-b)%MOD + MOD)%MOD; }
inline int mul(int a, int b){ return ((ll)a*b)%MOD; }

int n, s;
vector<int> a;
v2<int> dp;

int f(int index, int sum){
    if(sum < 0) return 0;
    if(index==-1) return sum==0;
    if(dp[index][sum] != -1) return dp[index][sum];

    dp[index][sum] = add(mul(2,f(index-1, sum)), f(index-1, sum-a[index]));
    return dp[index][sum];
}

void solve(){
    cin >> n >> s;
    a = vector<int>(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    dp = fill(n, s+1, -1);
    cout << f(n-1, s) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}