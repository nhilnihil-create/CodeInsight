//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll n; cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    ll m=n/2;
    ll num=0;

    vector<ll>b(n);
    for(int i=m;i<n;i++){
        if(a[i]==0)b[i]=0;
        else {
            b[i]=1;
            num++;
        }
    }

    for(int i=m-1;i>=0;i--){
        ll c=i+(i+1);
        ll d=0;
        while(c<n){
            d+=b[c];
            c+=i+1;
        }
        if(d%2==0&&a[i]==0)b[i]=0;
        else if(d%2==1&&a[i]==1)b[i]=0;
        else {
            b[i]=1;
            num++;
        }
        
    }

    cout<<num<<endl;
    rep(i,n){
        if(b[i]==1)cout<<i+1<<" ";
    }
    cout<<endl;

}

























