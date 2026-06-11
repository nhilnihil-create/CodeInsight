#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i,n) cin>>a[i];
    b=a;
    sort(b.begin(),b.end());

    rep(i,n){
        if(a[i]!=b[n-1]) cout<<b[n-1]<<"\n";
        else cout<<b[n-2]<<"\n";
    }
    return 0;
}