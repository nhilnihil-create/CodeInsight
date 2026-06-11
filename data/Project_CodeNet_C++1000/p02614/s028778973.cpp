#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int h,w,k;
    cin>>h>>w>>k;
    string c[h];
    rep(i,h)cin>>c[i];
    int ans=0;
    rep(i,1<<h){
        rep(j,1<<w){
            int cnt=0;
            rep(a,h){
                rep(b,w){
                    if(((i>>a)&1)&&((j>>b)&1)&&(c[a][b]=='#')){
                        ++cnt;
                    }
                }
            }
            if(cnt==k)++ans;
        }
    }
    cout<<ans<<endl;
}
