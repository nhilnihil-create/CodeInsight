#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n,m,x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n){
        cin >> c[i];
        rep(j,m) cin >> a[i][j];
    }
    vector<int> skill(m);
    int cost=-1;
    
    for(int bit=0; bit<(1<<n); bit++){
        int sum=0;
        rep(i,n){
            if(bit & (1<<i)){
                rep(j,m) skill[j]+=a[i][j];
                sum+=c[i];
            }
        }
        bool ans=true;
        rep(i,m){
            if(skill[i]<x) ans=false;
            skill[i]=0;
        }
        if(ans){
            if(cost==-1) cost=sum;
            else cost=min(cost,sum);
        }
        // if(ans) cout << 0 << ' ';
        // else cout << 1 << ' ';
        // cout << sum << endl;
    }

    cout << cost << endl;

    return 0;
}