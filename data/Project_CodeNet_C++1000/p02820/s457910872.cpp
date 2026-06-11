#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll ans=0;
    vector<char>memo;
    ll n,k;cin >>n>>k;
    ll r,s,p;cin >>r>>s>>p;
    string t;cin >>t;
    for (int i = 0; i < n; ++i) {
        if(i<k){
            if(t[i]=='r'){
                ans+=p;
                memo.push_back('p');
            }
            else if(t[i]=='s'){
                ans+=r;
                memo.push_back('r');
            }
            else {
                ans+=s;
                memo.push_back('s');
            }
        }
        else {
            if(t[i]=='r'){
                if(memo[i-k]=='p'){
                    memo.push_back('a');
                }
                else {
                    ans += p;
                    memo.push_back('p');
                }
            }
            else if(t[i]=='s'){
                if(memo[i-k]=='r'){
                    memo.push_back('a');
                }
                else {
                    ans += r;
                    memo.push_back('r');
                }
            }
            else {
                if(memo[i-k]=='s'){
                    memo.push_back('a');
                }
                else {
                    ans += s;
                    memo.push_back('s');
                }
            }
        }
    }
    cout <<ans<<endl;
    return 0;
}