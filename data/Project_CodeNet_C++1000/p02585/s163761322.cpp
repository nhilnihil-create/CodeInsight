#include <iostream>
#include<cmath>
#include<vector>
#include<tuple>
#include <ctime>
#include<algorithm>
#include <initializer_list>
#include <cstring> 
 
#define tii tuple<int,int>
#define vi vector<int>
#define vii vector<vi>
#define ll long long
#define vl vector<ll>
#define vll vector<vl>
 
#define mymod 1000000007
#define mx 99999999
#define mn -99999999
#define sz 101
 
using namespace std;
ll n,k;
 
int main() {
    clock_t tstart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Start
    cin>>n>>k;
    vl p(n);
    vl c(n);
    for(auto &x:p) cin>>x;
    for(auto &x:p) x--;
    for(auto &x:c) cin>>x;
    ll ans = *max_element(c.begin(),c.end());
    for(ll i=0;i<n;i++) {
        vl vec; vec.push_back(c[i]);
        ll j = p[i];
        ll s = c[i];
        while(j != i) {
            s += c[j];
            vec.push_back(s);
            j = p[j];
        }
        ll len =  vec.size();
        for(ll j1=0;j1<len;j1++){
            ll rest=k-j1-1;
            if(rest<0) break;
            ans=max(ans,vec[j1]+(rest/len)*max(s,0LL));
        }
    }
    cout<<ans;
    // cout<<"\n\nTotal Time Taken : "<<(double)(-tstart + clock())/CLOCKS_PER_SEC<<"sec\n\n";
    return 0;
}
 
