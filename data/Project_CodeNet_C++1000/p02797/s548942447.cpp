#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,k,s;
    cin>>n>>k>>s;
    rep(i,n){
        if(i<k)cout<<s<<" ";
        else{
            if(s!=1e9)cout<<1000000000<<" ";
            else cout<<1<<" ";
        }
    }
    return 0;
}
