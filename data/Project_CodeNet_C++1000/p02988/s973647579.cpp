#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int n;cin>>n;
    vector<int>p(n);
    rep(i,n){
        cin>>p.at(i);
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        if(p.at(i-1)<p.at(i)){
            if(p.at(i)<p.at(i+1)){
                ans++;
            }
        }
        if(p.at(i-1)>p.at(i)){
            if(p.at(i)>p.at(i+1)){
                ans++;
            }
        }   
    }
    cout<<ans<<endl;
}

