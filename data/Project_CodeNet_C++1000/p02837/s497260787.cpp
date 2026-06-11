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

int main(){
    int n;
    cin>>n;
    vector<vector<int>> shouziki(n,vector<int>(n,-1));
    rep(i,n){
        int a;
        cin>>a;
        rep(j,a){
            int x,y;
            cin>>x>>y;
            x--;
            shouziki[i][x]=y;
        }
    }

    int ans=0;
    for(int bit=0; bit<(1<<n); bit++){
        int count=0;
        vector<int> a;
        rep(i,n){
            if(bit&(1<<i)) a.push_back(1);
            else a.push_back(0);
        }
        bool judge=true;
        rep(i,n){
            if(a[i]==1){
                rep(j,n){
                    if(shouziki[i][j]!=a[j]&&shouziki[i][j]!=-1) judge=false;
                }
            }
        }
        if(judge) {
            rep(i,n){
                if(a[i]==1) count++;
            }
            ans=max(ans,count);
        }
        a.clear();
    }
    cout<<ans<<endl;
}
