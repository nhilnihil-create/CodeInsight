#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=15000007;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e17;
const long double PI=acos(-1);



void solve(int T){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<int>v1(a);
    vector<int>v2(b);
    vector<int>v3(c);
    vector<int>ans;
    for(int i=0;i<a;i++){
        cin>>v1[i];
    }
    for(int i=0;i<b;i++){
        cin>>v2[i];
    }
    for(int i=0;i<c;i++){
        cin>>v3[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    int i=a-1,j=x;
    while(j--){
        ans.pb(v1[i--]);
    }
    i=b-1;
    j=y;
    while(j--){
        ans.pb(v2[i--]);
    }
    i=c-1;
    j=x+y;
    while(j-- && i>=0){
        ans.pb(v3[i--]);
    }
    sort(ans.begin(),ans.end());
    i=ans.size()-1,j=x+y;
    ll fans=0;
    while(j--){
        fans+=ans[i--];
    }
    cout<<fans<<"\n";
}

int main() {
    fastio
    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
        //if(i<T)cout<<"\n";
    }
    return 0;
}



