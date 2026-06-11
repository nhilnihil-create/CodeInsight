#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

vector<string>anslist;
void dfs(string s){
    if(s.size()==3){
        anslist.push_back(s);
        return;
    }
    s+='0';
    for (int i = 0; i < 10;++i) {
        dfs(s);
        s.back()++;
    }
}

int main(){
    dfs("");
//    for(auto p:anslist){
//        cout <<p<<endl;
//    }ok
    ll n;cin >>n;
    string s;cin >>s;
    ll ans=0;
    for(auto p:anslist){
        ll k=0;
        for (int i = 0; i < n; ++i) {
            if(s[i]==p[k]){
                k++;
            }
            if(k==3){
                ans++;
                break;
            }
        }
    }
    cout <<ans <<endl;
    return 0;
}
