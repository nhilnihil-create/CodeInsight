#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define rept(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(v) v.bigin(),v.end()
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a<b?a:b
int main(){
    ll x[5],a;
    rep(i,5){
        cin>>x[i];
        if(x[i]==0){
            a=i+1;
        }
    }
    cout<<a;

}

