#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll  = long long;
using v   = vector<int>;
using P   = pair<int,int>;
using vp  = vector<P>;
using vvp = vector<vp>;

int main(){
    int n;
    string s;
    cin>>n>>s;
    
    ll r=0,g=0,b=0;
    
    rep(i,n){
        if(s[i]=='R')r++;
        else if(s[i]=='G')g++;
        else b++;
    }
    
    ll del = 0;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(j+(j-i)>=n)continue;
            if(s[i]==s[j])continue;
            if(s[j]==s[j+j-i])continue;
            if(s[i]==s[j+j-i])continue;
            del++;
        }
    }
    
    cout << r*g*b - del << endl;
    
    return 0;
}