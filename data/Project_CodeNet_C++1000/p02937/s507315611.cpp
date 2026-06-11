#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    string s,t;cin >>s>>t;
    s+=s;
    ll n=s.size();
    vector<vector<ll>>list(28,vector<ll>());
    for (int i = 0; i < n; ++i) {
        list[s[i]-'a'].push_back(i);
    }
    ll m=t.size();
    ll key=-1;
    ll ans=1;
//    for (int i = 0; i < 26; ++i) {
//        cout <<(char)('a'+i)<<" ";
//        for(auto u:list[i]){
//            cout <<u<<" ";
//        }
//        cout <<endl;
//    }
    for (int j = 0; j < m; ++j) {
        if(list[t[j]-'a'].empty()){
            cout <<-1<<endl;
            return 0;
        }
        ll k=upper_bound(all(list[t[j]-'a']),key)-list[t[j]-'a'].begin();
        k=list[t[j]-'a'][k];
//        cout <<k<<" "<<key <<endl;
        if(key<0)key=0;
        ans+=k-key;
        key=k;
        if(key>=n/2)key-=n/2;
    }
    cout <<ans <<endl;
    return 0;
}

