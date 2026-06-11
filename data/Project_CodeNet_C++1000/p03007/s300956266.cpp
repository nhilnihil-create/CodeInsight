#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];
    sort(all(a));
    
    vector<pair<int,int>> ans;
    if(a[0]>0){
        rep(i,1,n-1){
            ans.emplace_back(a[0],a[i]);
            a[0]-=a[i];
        }
        ans.emplace_back(a[n-1],a[0]);
        a[n-1]-=a[0];
        
        cout<<a[n-1]<<endl;
        for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
    }
    else if(a[0]<=0 && a[n-1]>0){
        int x=0;
        while(a[x]<=0) x++;
        
        rep(i,x,n-1){
            ans.emplace_back(a[0],a[i]);
            a[0]-=a[i];
        }
        
        rep(i,0,x){
            ans.emplace_back(a[n-1],a[i]);
            a[n-1]-=a[i];
        }
        
        cout<<a[n-1]<<endl;
        for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
    }
    else {
        rep(i,0,n-1){
            ans.emplace_back(a[n-1],a[i]);
            a[n-1]-=a[i];
        }
        
        cout<<a[n-1]<<endl;
        for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
    }
}

