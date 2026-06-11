#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007
const int N = 2005;
int s;
int dp[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 0;
    for(int i = 3; i <= s; i++){
        for(int j = 3; j <= i; j++){
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }    
    cout<<dp[s]<<"\n";
}