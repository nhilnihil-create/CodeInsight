#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m,d,res=0;
    cin>>m>>d;
    for(ll z=1;z<=m;z++)
    for(ll i=10;i<=d;i++){
        ll x=i/10,y=i%10;
        if(x>=2&&y>=2&&(x*y==z))
        res++;
    }
    cout<<res;
}
