#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    map<string,int> mp;
    string s;
    int n;
    cin>>n;
    rep(i,n){
        cin>>s;
        sort(all(s));
        mp[s]++;
    }
    ll ans=0;
    for(auto &a:mp){
        ll num=a.second;
        ans+=num*(num-1)/2;
    }
    cout<<ans;
}