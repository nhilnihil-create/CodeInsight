#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define fi first
#define se second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    vvi ans(h,vi(w,-1));
    for(int i=0;i<b;i++){
        for (int j=0;j<a;j++){
            ans[i][j]=0;
        }
        for(int j=a;j<w;j++){
            ans[i][j]=1;
        }
    }
    for(int i=b;i<h;i++){
        for (int j=0;j<a;j++){
            ans[i][j]=1;
        }
        for (int j=a;j<w;j++){
            ans[i][j]=0;
        }
    }
    rep(i,h){
        rep(j,w){
            cout<<ans[i][j];
        }
        cout<<endl;
    }

    return 0;
}