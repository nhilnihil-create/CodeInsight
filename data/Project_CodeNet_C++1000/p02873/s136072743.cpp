#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;
ll SUM(ll n){
    ll ans=0;
    for(ll i=1;i<=n;i++)ans+=i;
    return ans;
}

int main() {
    string s; cin >> s; s = s+'.';
    ll ans=0;
    vector<ll> v;
    char start=s[0];
    ll count=1;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]) count++;
        else {v.push_back(count); count=1;}
    }
    if(start=='<'){
        for(int i=0;i<v.size()/2;i++){
            ans+=SUM(v[i*2])+SUM(v[i*2+1])-min(v[i*2], v[i*2+1]);
        }
        if(v.size()%2!=0) ans+=SUM(v[v.size()-1]);
    }else{
        ans+=SUM(v[0]);
        if(v.size()%2==0) ans+=SUM(v[v.size()-1]);
        for(int i=0;i<(v.size()-1)/2; i++){
            ans += SUM(v[i*2+1]) + SUM(v[i*2+2]) - min(v[i*2+1],v[i*2+2]);
        }
    }
    cout << ans << endl;
}