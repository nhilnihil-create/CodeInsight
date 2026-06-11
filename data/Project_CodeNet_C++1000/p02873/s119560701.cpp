#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    string s;cin >>s;
    char key='<';
    vector<ll>cnt;
    ll now=0;
    for (int i = 0; i < s.size(); ++i) {
        if(key==s[i]){
            now++;
        }
        else {
            if(key=='<')key='>';
            else key='<';
            cnt.push_back(now);
            now=1;
        }
    }
    if(now!=0)cnt.push_back(now);
    if(cnt.size()%2==1)cnt.push_back(0);
    vector<ll>sum;
    ll pl=0;
    for (int i = 0; i <=s.size(); ++i) {
        pl+=i;
        sum.push_back(pl);
    }
    ll ans=0;
    for (int i = 0; i < cnt.size(); i+=2) {
        ll mx=max(cnt[i],cnt[i+1]);
        ll mint=min(cnt[i],cnt[i+1]);
        ll tmp=max(0LL,mint-1);
        ans+=sum[mx]+sum[tmp];
    }
    cout <<ans <<endl;
    return 0;
}

