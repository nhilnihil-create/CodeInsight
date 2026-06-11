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
    vector<int> tmp(0);
    while(n){
        ll x;
        x=n%26;
        tmp.push_back(x);
        n/=26;
        if(x==0) n--;
    }
    for(int i=tmp.size()-1;i>=0;i--){
        int shift=tmp[i]-1;
        char ans='a'+shift;
        if(shift>=0) cout << ans;
        else cout << 'z';
    }
    cout << endl;
}