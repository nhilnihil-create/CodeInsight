#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N,K,S;
    cin >> N >> K >> S;
    vector<ll> res(N,0);
    ll len=(N-K)+1;
    if(len<=S){
        ll mod=S%len;
        ll unit=S/len;
        for(ll i=1;i<=N;i++)
        {
            if(i%len==0)cout<<unit+mod;
            else cout<<unit;
            if(i!=N)cout<<" ";
        } 
    }
    else{
        ll padding=len-S;
        for(ll i=0;i<N;i++)
        {
            if(i<padding)cout<<1+S;
            else cout<<1;
            if(i!=N-1)cout<<" ";
        } 
    }
    return 0;
}