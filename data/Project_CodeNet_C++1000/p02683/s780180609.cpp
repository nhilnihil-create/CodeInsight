#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

int main(){
    int n,m,x,ans=10000000;
    cin >> n >> m >> x;
    vector<int> cost(n);
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n){
        cin >> cost[i];
        rep(j,m)
            cin >> a[i][j];
    }
    for(int bit=1;bit < (1<<n);bit++){
        int sum=0;
        vector<int> xadd(m);
        rep(i,n){
            if(bit & (1<<i)){
                rep(j,m) xadd[j]+=a[i][j];
                sum+=cost[i];
            }
        }   
        bool flag=true;
        rep(i,m){
            if(xadd[i] < x){
                flag=false;
                break;
            }
        }
        if(flag){
            ans=min(ans,sum);
        }
    }
    if(ans==10000000){
        cout << -1 << endl;
        return 0;
    }else{
        cout << ans << endl;
        return 0;
    }
    /*
    rep(i,n){
        cout << cost[i] << " ";
        rep(j,m){
            cout << r[i][j] << " ";
        }
        cout << endl;
    }*/
}