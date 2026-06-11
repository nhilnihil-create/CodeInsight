#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n;
    cin>>n;
    ll a[n];
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum^=a[i];
    }
    rep(i,n){
        cout<<(sum^a[i])<<" ";
    }
    cout<<endl;
}
