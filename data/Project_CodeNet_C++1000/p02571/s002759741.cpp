#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
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
    int ans=INT_MAX;
    string s,t;
    cin>>s>>t;
    rep(i,s.size()-t.size()+1){
        int a=t.size();
        rep(j,t.size()) if(s[i+j]==t[j]) a--;
        ans=min(ans,a);
    }
    cout<<ans;
}