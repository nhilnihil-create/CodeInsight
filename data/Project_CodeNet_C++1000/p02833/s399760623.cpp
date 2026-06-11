//#define _GLIBCXX_DEBUG
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
    if(n%2!=0){
        cout<<0<<endl;
        return 0;
    }
    ll ans=0;
    ll w=5;
    while(1){
        ans+=n/(w*2);
        if(n/(w*2)==0)break;
        w*=5;
    }
    cout<<ans<<endl;
}







































