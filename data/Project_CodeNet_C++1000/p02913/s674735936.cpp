#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n;
    string s;cin>>n>>s;
    vector<ll> tmp;
    ll an=0;
    rep(i,1,n){
        tmp.clear();
        ll temp=0;
        rep(j,0,n){
            if(j+i>=n)continue;
            
            if(s[j+i]==s[j])tmp.push_back(j);
        }
        ll tempo=0;
        rep(j,1,tmp.size()){
            if(tmp[j-1]+1==tmp[j])tempo++;
            else{
                temp=max(temp,tempo+1);
                tempo=0;
            }
        }
        if(tempo!=0)temp=max(temp,tempo+1);
        an=max(an,min(temp,(ll)i));
    }
    cout<<an<<endl;
}

    







