#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;

int main(){
    int x,n; cin>>x>>n;
    int p[n];
    rep(i,n) cin>>p[i];
    bool neko=true;
    rep(i,n){
        if(p[i]==x) neko=false;
    }
    if(neko){
        cout<<x<<endl;
        return 0;
    }
    int a= x-1, b=x+1;
    rep(i,n){
        bool an=true,bn=true;
        for(int j=0; j<n;j++){
            if(p[j]==a) an=false;
            if(p[j]==b) bn=false;
        }
        if(an){
            cout<<a<<endl;
            return 0;
        }
        if(bn){
            cout<<b<<endl;
            return 0;
        }
        a--; b++;
    }
    cout<<a<<endl;
}
