#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
bool calc(vector<ll> &a,vector<ll> &f,ll t,ll k,ll n){
    ll cnt=0;
    For(i,0,n)cnt+=max(a[i]-t/f[i],0LL);
    return cnt<=k;
}
void Main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n),f(n);
    For(i,0,n) cin>>a[i];
    For(i,0,n) cin>>f[i];
    sort(ALL(a));
    sort(ALL(f));
    reverse(ALL(f));
    ll ok=1e13,ng=-1;
    while(ok>ng+1){
        ll mid=(ok+ng)/2;
        if(calc(a,f,mid,k,n)==true)ok=mid;
        else ng=mid; 
    }
    cout<<ok<<endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}