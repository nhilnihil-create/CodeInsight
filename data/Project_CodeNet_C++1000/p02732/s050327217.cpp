#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 5e4+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
//#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int n;
    cin>>n;
    map<int,ll> mp;
    ll arr[n];
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        arr[i]=x;
        mp[x]++;
    }
    ll ans=0;
    for(auto x: mp){
        ll temp=x.second;
        ans=ans+(temp*(temp-1))/2;
    }
    for(int i=0;i<n;i++){
        ll temp=mp[arr[i]];
        cout<<ans-(temp*(temp-1))/2+((temp-1)*(temp-2))/2<<endl;
    }
}