#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

int main(){
    ll n; cin>>n;
    vector<ll>a(n);
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        if(i%2==0)sum+=a[i];
        else sum-=a[i];
    }
    vector<ll>ans(n);
    ans[0]=sum;
    rep(i,n-1){
        ans[i+1]=2*a[i]-ans[i];
    }
    rep(i,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}






































