#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    ll ans3=0,ans2;
    rep(i,n){
        cin >> a[i];
        ans3+=a[i];
    }
    vector <vector <ll>> ans(n-1, vector <ll> (2));
    sort(a.begin(),a.end());
    
        rep(i,n-2){
            if(a[i+1]>=0){
                ans[i][0]=a[0];
                ans[i][1]=a[i+1];
                a[0]-=a[i+1];
            }
            else{
                ans[i][0]=a[n-1];
                ans[i][1]=a[i+1];
                a[n-1]-=a[i+1];
            }
        }
        ans[n-2][0]=a[n-1];
        ans[n-2][1]=a[0];
        ans2=a[n-1]-a[0];
    

    cout << ans2 << endl;
    rep(i,n-1){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    
    

    return 0;
}