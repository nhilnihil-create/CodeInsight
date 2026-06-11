#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int h,n;
    cin >> h >> n;
    vector <int> a(n),b(n);
    rep(i,n){
        cin >> a[i] >> b[i]; 
    }
    vector <vector <int>> ans(n,vector <int> (h+1));

    rep(i,h+1){
        if(i==0){
            ans[0][i]=b[0];
        }
        else{
        ans[0][i]=((i-1)/a[0]+1)*b[0];
        }
    }

    rep(i,n-1){
        rep(j,h+1){
            if(j<=a[i+1]){
                ans[i+1][j]=min(ans[i][j],b[i+1]);
            }
            else{
                ans[i+1][j]=min(ans[i+1][j-a[i+1]]+b[i+1],ans[i][j]);
            }
            //cout << ans[i][j] << endl;
        }
        
    }

    cout << ans[n-1][h] << endl;

    

    return 0;
}