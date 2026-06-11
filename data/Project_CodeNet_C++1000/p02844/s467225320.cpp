#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    rep(i,10)rep(j,10)rep(k,10){
        int z=0;
        rep(a,n){
            if(z==0&&s[a]-'0'==i) z=1;
            else if(z==1&&s[a]-'0'==j) z=2;
            else if(z==2&&s[a]-'0'==k) z=3;
        }
        if(z==3) ans++;
    }
    cout<<ans;
}