#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    vector<int64_t> sum(n+1,0);
    //sum[n]=a[0]-a[1]+a[2]+....-a[n]
    rep(i,n){
        if(i%2==0){
            sum[i+1] = sum[i] + a[i];
        }
        else{
            sum[i+1] = sum[i] - a[i];
        }
    }
    rep(i,n){
        int64_t ans;
        if(i%2==0){
         ans= sum[n]-sum[i] - sum[i];
        }
        else{
            ans =-(sum[n]-sum[i]) + sum[i];
        }
        cout<<ans<<" ";
    }
}