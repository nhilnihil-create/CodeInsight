#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    fast_io

    ll n, mean=0;
    cin>>n;
    vector<ll> A(n);
    rep(i,n) cin>>A[i];
    
    ll li=1, ri=n-1;
    ll l=A[0], r=0;
    while(li<=ri){
        if(l>r){
            r+=A[ri];
            ri--;
        }
        else if(l<=r){
            l+=A[li];
            li++;
        }
        //cout<<l<<" "<<r<<endl;
    }
    cout<<abs(r-l)<<endl;

    return 0;
}