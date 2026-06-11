#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int k;
    cin>>k;
    ll ans=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                ans+=gcd(gcd(i,j),l);
            }
        }
    }
    cout<<ans<<endl;
}