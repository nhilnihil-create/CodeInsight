#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,m,a[3],s,c;
    cin>>n>>m;
    rep(i,3){
        a[i]=-1;
    }
    rep(i,m){
        cin>>s>>c;
        if(a[s-1]!=-1&&a[s-1]!=c){
            cout<<"-1";
            return 0;
        }
        if(n==2&&s==1&&c==0){
            cout<<"-1";
            return 0;
        }
        if(n==3&&s==1&&c==0){
            cout<<"-1";
            return 0;
        }
        a[s-1]=c;
    }
    rep(i,n){
        if(a[i]==-1){
          if(i==0&&n>1){
            a[0]=1;
          }else{
            a[i]=0;
          }
        }
        cout<<a[i];
    }
    cout<<endl;
}