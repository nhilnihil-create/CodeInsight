#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>a(n);
    rep(i,n) cin>>a.at(i);
    long long ans=1;
    rep(i,n){
        if(ans<=1000000000000000000/a.at(i)) ans*=a.at(i);
        else{
            ans=-1;
            break;
        }
    }
    rep(i,n){
        if(a.at(i)==0) ans=0;
    }
    cout<<ans;
}