#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    int N;cin>>N;
    map<string,int> m;
    for (int i = 0; i < N; i++){
        string s; cin>>s;
        sort(s.begin(),s.end());
        m[s]++;
    }
    ll ans=0;
    for(auto p:m){
        ll x=p.second;
        ans+=x*(x-1)/2;
    }
    cout<<ans<<endl;
}