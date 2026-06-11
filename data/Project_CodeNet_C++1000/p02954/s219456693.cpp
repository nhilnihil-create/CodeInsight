#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;
 
 
int main(){
    ll n,k,a[2000005],cnt=0,ans=0;
    string s;
    cin>>s;
    k=s.size();
    rep(i,k){
        a[i]=0;
    }
    rep(i,k){
        if(s[i]=='R'){
            cnt++;
        }else{
            a[i-1]+=(cnt+1)/2;
            a[i]+=cnt/2;
            cnt=0;
        }
    }
    for(int i=k-1;i>=0;i--){
        if(s[i]=='L'){
            cnt++;
        }else{
            a[i+1]+=(cnt+1)/2;
            a[i]+=cnt/2;
            cnt=0;
        }
    }
    rep(i,k){
        cout<<a[i];
        if(i<k-1) cout<<" ";
    }
}