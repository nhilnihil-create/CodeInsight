#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    long long N;
    cin>>N;
    vector<ll> L(N,0);
    for(ll i=0;i<N;i++)
    {
        cin>>L[i];
    }
    sort(L.begin(),L.end());
    // L.erase(std::unique(L.begin(), L.end()), L.end()); 
    ll res=0;
    for(ll a=0;a<N;a++){
        for(ll b=a+1;b<N;b++){
            for(ll c=b+1;c<N && L[c]<L[a]+L[b];c++){
                if(L[a]<L[b]+L[c] && L[b]<L[a]+L[c])
                {
                    res++;
                }
            }
        }
    }
    cout<<res;
}