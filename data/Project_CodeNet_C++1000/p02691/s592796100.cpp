
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define F first
#define S second
#define def(x) cerr << #x << " is " << x << endl;
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(ll i=a;i<n;i++)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(a) a.begin(),a.end()
const int NUM = 2e5 + 5;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
int main(){
    ios
    int num_tests=1; 
    //cin>>num_tests;
    while(num_tests-->0){
        ll n; cin>>n;
        vector<ll> a(n+1,0);
        FOR(i,1,n+1) cin>>a[i];
        vector<ll> sum(n+1,0),diff(n+1,0);
        FOR(i,1,n+1) sum[i] = a[i]+i,diff[i] = i-a[i];
        ll ans = 0;
        map<ll,ll> mp;
        for(ll i=n;i>=1;i--){
            ans+=mp[sum[i]];
            mp[diff[i]]++;
        }
        cout<<ans;
    }   
}

