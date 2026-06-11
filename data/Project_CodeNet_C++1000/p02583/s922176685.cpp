#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
using namespace std;
using ll=long long;
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }

int main(){
    int n,cnt=0;
    cin>>n;

    ll l[105];
    rep(i,n) cin>>l[i];
    rep(i,n)rep(j,n)rep(k,n){
        if(l[i]==l[j] || l[j]==l[k] || l[k]==l[i]){
            continue;
        }
        if(i<j && j<k){
            if(l[i]+l[j]>l[k] && l[i]+l[k]>l[j] && l[j]+l[k]>l[i]){
                cnt++;
            }
        }

    }
    cout<<cnt<<endl;
    return 0;
}