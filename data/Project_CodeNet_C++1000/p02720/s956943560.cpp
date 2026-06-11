#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG


void dfs (ll keta , ll n , vector<ll> &a){
    if(keta==11){
        return;
    }

    a.push_back(n);
    for(int i=-1;i<2;i++){
        int res=n%10;
        if(res+i>=0&&res+i<=9) {
            
            dfs(keta+1,n*10+res+i,a);
        }
    }
}

int main(){
    int k;
    cin>>k;
    vector<ll> a;
    rep1(i,9){
        dfs(1,i,a);
    }
    sort(a.begin(),a.end());
    cout<<a[k-1]<<endl;
}