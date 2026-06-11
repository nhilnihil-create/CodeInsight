#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int f(int x){
    if(x==3) return 100000;
    if(x==2) return 200000;
    if(x==1) return 300000;
    else return 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x,y;cin>>x>>y;
    int ans = f(x) + f(y);
    if(x==1 && y==1) ans+=400000;
    cout<<ans<<endl;
}
// ddcc2020_qual_a