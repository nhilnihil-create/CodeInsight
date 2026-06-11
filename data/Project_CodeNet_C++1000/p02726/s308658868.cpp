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

int a[2003][2003];

void solve(int T){
    map<int,int>mp;
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=abs(i-j);
        }
    }
    a[x][y]=1;
    a[y][x]=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==j-1){
                mp[a[i][j]]++;
            }
            else {
                a[i][j]=min(a[i][j],a[i][x]+a[j][y]+1);
                mp[a[i][j]]++;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(mp.count(i)){
            cout<<mp[i]<<"\n";
        }
        else cout<<"0\n";
    }
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



