#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    int n,m;cin>>n>>m;
    vector<set<int>> vs(n);
    int s,c;
    rep(i,m){
        cin>>s>>c;
        s--;
        vs[s].insert(c);
    }
    
    if(n>1 && vs[0].count(0)){
        cout << -1 << endl;
        return 0;
    }
    
    rep(i,n){
        if(vs[i].size()>1){
            cout << -1 << endl;
            return 0;
        }
    }
    
    if(n==1){
        if(vs[0].size()){
            for(auto p: vs[0])
                cout << p << endl;
            return 0;
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }
    
    if(vs[0].size()){
        for(auto p: vs[0])
            cout << p;
    }else{
        cout << 1;
    }
    for(int i=1; i<n; i++){
        if(vs[i].size()){
            for(auto p: vs[i])
                cout << p;
        }else{
            cout << 0;
        }
    }
    
    cout << endl;
    
    return 0;
}