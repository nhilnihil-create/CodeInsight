#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int ans[1100][1100];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w,a,b; cin>>h>>w>>a>>b;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if((i<b && j<a) || (i>=b && j>=a)){
                ans[i][j]=1;
            }
        }
    }

    for(int i=0; i<h;i++){
        for(int j=0;j<w;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }

}