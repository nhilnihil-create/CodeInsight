#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lld long double
#define w(x) ll x;cin>>x;while(x--)
#define mod 1000000007
#define speed ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
    speed;
    ll h,w,k;  cin>>h>>w>>k;
    vector<vector<char>> a(h,vector<char>(w));
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    ll ans=0;
    for(ll i=0;i<(1<<h);i++){
        for(ll j=0;j<(1<<w);j++){
            ll black=0;
            for(ll p=0;p<h;p++){
                if(i&(1<<p))    continue;
                else{
                    for(ll l=0;l<w;l++){
                        if(j&(1<<l))    continue;
                        if(a[p][l]=='#')  black++;
                    }
                }
            }    
            if(black==k)    ans++; 
        }
    }
    cout<<ans<<'\n';
    return 0;
}