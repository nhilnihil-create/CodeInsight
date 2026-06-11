#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REV(i,a,n) for(int i=a;i>=n;i--)
#define all(a) a.begin(),a.end()
#define UB upper_bound
#define LB lower_bound
const int NUM = 2e5 + 5;
int MOD = 2019;
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num_tests=1; 
    //cin>>num_tests;
    while(num_tests-->0){
        string s; cin >> s;
        int ans = 0;
        int n = s.size();
        map<int,int> ma;
        int rem = 0;
        int mul = 1;
        ma[0]++;
        REV(i,n-1,0){
            int x = s[i] - '0';
            rem = x*mul + rem;
            rem %= MOD;
            ans += ma[rem];
            ma[rem]++;
            mul *= 10;
            mul %= MOD;
        }
        cout << ans;
    }   
}