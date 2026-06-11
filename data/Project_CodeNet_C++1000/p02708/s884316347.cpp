#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define aint(a) a.begin(),a.end()
#define UB upper_bound
#define LB lower_bound
const int NUM = 2e5 + 5;

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num_tests=1; 
    //cin>>num_tests;
    while(num_tests-->0){
        int N, K; cin >> N >> K;
    int pre = 0;
    int suf = 0;
    int ans = 0;
    FOR(i, 1, N+2) {
        pre += i-1;
        suf += N+1-i;
        pre %= mod; suf %= mod;
        if (i >= K) {
            ans += suf - pre + 1 + mod;
            ans %= mod;
        }
    }
        cout << ans;
    }   
}