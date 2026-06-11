#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n,all; cin>>n;
    int a[n];
    rep(i,n){
        cin>>a[i];
        (i==0) ? all=a[i] : all=all^a[i];
    }
    rep(i,n) cout<<(all^a[i])<<endl;
}