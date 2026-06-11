#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define lint long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
int n,m,v,p;
bool judge(vector<int> const& a,int key){
    bool res=true;
    if(key<p){
        return true;
    }
    if(a[key]+m<a[p-1]){
        return false;
    }
    int rem=m*v;
    rem-=(n-key)*m;
    if(rem<=0){
        return true;
    }
    int sum=a[key]+m;
    for(int i=0;i<key;++i){
        if(i<p-1){
            rem-=m;
            continue;
        }
        rem-=sum-a[i];
    }
    return rem<=0;
}
signed main(){
    cin>>n>>m>>v>>p;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    reverse(ALL(a));
    rep(i,n){
        //cout<<a[i]<<" ";
    }
    //cout<<endl;
    int d=0;int u=n;
    while(u-d>1){
        int mid=(u+d)/2;
        if(judge(a,mid)){
            d=mid;
        }
        else{
            u=mid;
        }
    }
    cout<<u<<endl;
    return 0;
}