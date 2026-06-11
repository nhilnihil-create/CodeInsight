#include <bits/stdc++.h>
#define pb push_back
#define p push
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vll vector<long long>
#define all(vec) begin(vec), end(vec)
#define pii pair<int,int>
#define plli pair<ll,int>
#define pill pair<ill>
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
ll dp[2010];
int s;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    dp[0] = 1;
    for(int i = 3; i <= s; i++){
        for(int j = 0; j <= i-3; j++){
            dp[i] = (dp[i]+dp[j])%(ll)1000000007;
        }
    }
    cout << dp[s] << '\n';
    return 0;
}

