#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 5e5+5;
// check for forloop
// take input
// overflow
// intialize variable
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    ll n,k;
    cin>>n>>k;
    if(k-n>2019){
        cout<<0;
    }
    else{
        ll ans=2019;
        for(ll i=n;i<k;i++){
            for(ll j=i+1;j<=k;j++){
                ans=min(ans,ll((i*j)%2019));
            }
        }
        cout<<ans;
    }
}
