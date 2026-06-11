#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <bitset>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll n;
    cin >> n;
    map<ll,ll> mp;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            mp[i]++;
            n/=i;
            i--;
        }
    }
    if(n!=1) mp[n]++;
    int ans=0;
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        for(int i=1;itr->second>=i;i++){
            ans++;
            itr->second-=i;
        }
    }
    cout << ans << endl;
}