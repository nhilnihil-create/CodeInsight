#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    int ans[h][w];
    rep(i,b){
        rep(j,a){
            ans[i][j]=0;
        }
        for(int j=a;j<w;j++){
            ans[i][j]=1;
        }
    }
    for(int i=b;i<h;i++){
        rep(j,a){
            ans[i][j]=1;
        }
        for(int j=a;j<w;j++){
            ans[i][j]=0;
        }
    }

    rep(i,h){
        rep(j,w){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}

