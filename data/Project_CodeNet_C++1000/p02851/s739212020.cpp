#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';

int cnt[200003],n,k;
long long ans;
map<int,int>mp;

int main(void) {
    cin>>n>>k;
    rep(i,n){
        cin>>cnt[i+1];
        cnt[i+1]+=cnt[i]-1;
        cnt[i+1]%=k;
    }
    mp[0]=1;
    rep(i,n) {
        if (i+1>=k)mp[cnt[i+1-k]]--;
        ans+=mp[cnt[i+1]], mp[cnt[i+1]]++;
    }
    cout<<ans;
}