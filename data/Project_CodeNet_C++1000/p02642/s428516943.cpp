#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;
using ll = long long;
const int INF=1e9;

int main(){
    int n,ans=0,r=0;
    cin>>n;
    map<int,int> a;
    rep(i,n){
        int x;
        cin>>x;
        r=max(r,x);
        a[x]++;
    }
    for(auto p:a){
        if(p.second==1) ans++;
        int i=p.first;
        while(i<=r){
            i+=p.first;
            a.erase(i);
        }
    }
    cout<<ans;
}