#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc = 1; 
    //cin >> tc;
    while(tc--){
        string s; cin >> s; 
        int n = s.size();
        int MOD = 2019;
        int ans = 0;
        map<int,int> mp;
        mp[0] = 1;
        int rem = 0, mul = 1;
        for(int i = n-1; i >= 0; i--)
        {
            int x = s[i] - '0';
            rem = ((mul*x) % MOD + rem) % MOD;
            ans += mp[rem];
            mul  = (mul*10) % MOD;
            mp[rem]++;
        }
        cout << ans;
    }    
}