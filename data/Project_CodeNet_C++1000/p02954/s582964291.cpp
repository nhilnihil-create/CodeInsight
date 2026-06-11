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
    string s;cin >>s;
    char key='R';
    vector<ll>cnt;
    ll now=0;
    ll n=s.size();
    for (int i = 0; i < n; ++i) {
        if(key==s[i]){
            now++;
        }
        else {
            if(key=='L'){
                key='R';
            }
            else {
                key='L';
            }
            cnt.push_back(now);
            now=1;
        }
    }
    cnt.push_back(now);
//    for (int i = 0; i < cnt.size(); ++i) {
//        cout <<cnt[i]<<" ";
//    }
//    cout <<endl;
    vector<ll>ans(n,0);
    ll k=0;
    for (int i = 0; i <cnt.size();i+=2) {
        k+=cnt[i]-1;
        ans[k]+=(cnt[i]-1)/2+1;
        ans[k]+=cnt[i+1]/2;
        ans[k+1]+=cnt[i]/2;
        ans[k+1]+=(cnt[i+1]-1)/2+1;
        k+=cnt[i+1]+1;
    }
    for (int i = 0; i < n; ++i) {
        cout <<ans[i]<<" ";
    }
    cout <<endl;
    return 0;
}