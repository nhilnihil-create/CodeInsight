#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;
#define PI 	3.14159265358979323846
ll lvl[15];
int books[15][15]; // books[i][0] is cost
int cost[15];


int main(){
    AC
    int n, m, x;
    cin>>n>>m>>x;
    for(int i=0; i<n; i++){
        cin>>cost[i];
        for(int j=0; j<m; j++){
            cin>>books[i][j];
        }
    }
        

    ll ans = -1;

    for(int i=0; i<(1<<n); i++){
        ll cur_cost = 0;
        memset(lvl, 0, sizeof(lvl));

        for(int j=0; j<n; j++){
            if((i>>j)&1){
                cur_cost+=cost[j];
                for(int k=0; k<m; k++){
                    lvl[k] += books[j][k];
                }
            }
        }

        bool flag = true;
        for(int j=0; j<m; j++){
            if(lvl[j]<x){
                flag = false;
                break;
            }
        }

        if(flag){
            if(ans==-1)
                ans = cur_cost;
            else
                ans = min(ans, cur_cost);
        }
    }

    cout<<ans<<endl;

}