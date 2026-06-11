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
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n+1);
    for(int i=1;i<=n;i++) cin >> A[i];
    map<ll,ll> mp;
    mp[1]=0;
    ll cycle1,cycle2,after_i=1;
    for(int i=1;i<=n;i++){
        after_i=A[after_i];
        if(mp.find(after_i)==mp.end()){
            mp[after_i]=i;
        }else{
            cycle1=mp[after_i];
            cycle2=i;
            break;
        }
    }
    ll place=1;
    if(k<=n){
        for(ll i=0;i<k;i++){
            place=A[place];
        }
    }else{
        if(cycle1!=0) k-=cycle1;
        k%=(cycle2-cycle1);
        if(cycle1!=0) k+=cycle1;
        for(ll i=0;i<k;i++){
            place=A[place];
        }
    }
    cout << place << endl;
}