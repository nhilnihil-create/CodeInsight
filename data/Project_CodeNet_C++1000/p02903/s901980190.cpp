#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    char ans[h][w];

    rep(i,h){
        rep(j,w){
            if(i<b && j<w-a) ans[i][j]='0';
            else if(i<b && j>=w-a) ans[i][j]='1';
            else if(i>=b && j<w-a) ans[i][j]='1';
            else ans[i][j]='0';
        }
    }

    rep(i,h){
        rep(j,w){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}