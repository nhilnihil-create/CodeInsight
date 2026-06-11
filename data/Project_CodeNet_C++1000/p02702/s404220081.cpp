#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    reverse(s.begin(),s.end());
    map<int,int>mp;
    mp[0]=1;
    int cnt=0,ten=1;
    rep(i,n){
        cnt=(cnt+(s[i]-'0')*ten)%2019;
        ten=ten*10%2019;
        mp[cnt]++;
    }
    ll ans=0;
    for(auto&p:mp){
        ans+=p.second*(p.second-1)/2;
    }
    cout<<ans<<endl;
}