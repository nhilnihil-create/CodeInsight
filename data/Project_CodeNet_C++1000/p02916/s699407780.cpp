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
    int N;cin>>N;
    vector<int>a(N);
    vector<int>b(N);
    vector<int>c(N-1);
    int ans=0;
    rep(i,N){
        cin>>a.at(i);
    }
    rep(i,N){
        cin>>b.at(i);
    }
    rep(i,N-1){
        cin>>c.at(i);
    }
    rep(i,N){
        if(i!=0){
            if(a.at(i)-a.at(i-1)==1){
                ans+=c.at(a.at(i-1)-1);
            }
        }
        ans+=b.at(a.at(i)-1);
    }
    cout<<ans<<endl;

}