#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define mod 1000000007 //10^9+7
#define INF 1000000000000 //10^12
#define F first
#define S second
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()
int n,k;
set<int>st;
int ans=0;
signed main(){
    cin>>n>>k;
    rep(i,k){
        int d;cin>>d;
        rep(i,d){
            int a;
            cin>>a;
            st.insert(a);
        }
    }
    for(int i=1;i<=n;i++){
        if(st.find(i)==st.end())ans++;
    }
    cout<<ans<<endl;
    return 0;
}

