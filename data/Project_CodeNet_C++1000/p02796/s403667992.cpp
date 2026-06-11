#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int n; cin >> n;
    vector<pair<int,int>> p(n);
    rep(i,n){
        int x,l;
        cin >> x >> l;
        p.at(i)=make_pair(x+l,x-l);
    }
    sort(p.begin(),p.end());
    int ans=0;
    int t=p.at(0).second;
    rep(i,n){
        if(t<=p.at(i).second){
            ans++;
            t=p.at(i).first;
        }
    }
    cout << ans << endl;
}