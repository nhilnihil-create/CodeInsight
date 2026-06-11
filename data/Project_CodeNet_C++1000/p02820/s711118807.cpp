#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n, k, r, s, p;
    cin>>n >>k >>r >>s >>p;
    vector<char> t(n);
    vector<bool> hand(n,true);
    long ans=0;
    rep(i,n){
        cin>>t[i];
        if(i<k){
            if(t[i]=='r') ans+=p;
            else if(t[i]=='s') ans+=r;
            else ans+=s;
        }else{
            if(t[i]==t[i-k] && hand[i-k]){
                ans+=0;
                hand[i]=false;
            }else if(t[i]=='r'){
                ans+=p;
            }else if(t[i]=='s'){
                ans+=r;
            }else if(t[i]=='p'){
                ans+=s;
            }
        }
    }
    cout<<ans<<endl;
}