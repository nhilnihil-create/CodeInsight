#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n;cin>>n;
    vll ans(n);
    vll a(n);
    rep(i,n){
        cin>>a[i];
        if(i%2==0)ans[0]+=a[i];
        else ans[0]-=a[i];
    }
    ans[0]/=2;
    rep(i,n-1)ans[i+1]=a[i]-ans[i];
    rep(i,n-1)cout<<2*ans[i]<<" ";
    cout<<2*ans[n-1]<<endl;
}