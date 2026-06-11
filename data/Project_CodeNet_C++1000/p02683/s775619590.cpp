#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,m,x,a[12][12],sum[12],c[12],price,goal,ans=-1;
    cin >> n >> m >> x ;
    for(int i=0;i<n;i++){
        cin >> c[i];
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<(1<<n);i++){
        goal=0;
        price=0;
        for(int j=0;j<m;j++){
            sum[j]=0;
        }
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                price+=c[j];
                for(int k=0;k<m;k++){
                    sum[k]+=a[j][k];
                }
            }
        }
        for(int j=0;j<m;j++){
            if(sum[j]<x){
                goal=1;
            }
        }
        if(goal==0){
            if(ans==-1||ans>price){
                ans=price;
            }
        }
    }
    cout << ans;
}