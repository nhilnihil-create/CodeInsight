#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 1000;
ll mod = INF;


int main(){
    int h,n;
    int a[1000],b[1000];
    int dp[10001];
    cin >> h>>n;
    for(int i=0;i<n;i++){
        cin >> a[i]>>b[i];
    }
    for(int i=0;i<=10000;i++){
        dp[i]=INF;
    }
    dp[0]=0;//dp[damage]=min(mana)
    for(int d=1;d<=10000;d++){
        for(int j=0;j<n;j++){
            if(d-a[j]<0){
                dp[d]=min(dp[d],b[j]);
            }else if(d-a[j]>=0){
                dp[d]=min(dp[d],dp[d-a[j]]+b[j]);
            }
        }
    }

    for(int i=h;i<=10000;i++){
        if(dp[i]!=INF){
            cout << dp[i]<<endl;
            break;
        }
    }
    
    return 0;
}