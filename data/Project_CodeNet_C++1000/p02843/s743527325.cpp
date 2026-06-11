#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x;cin>>x;
    int ans = 0;
    if(x<100) ans = 0;
    else for(int i=1; i<100000/100; i++){
        if(100*i <= x && x <= 105*i) ans = 1;
    }
    cout<<ans<<endl;
    
}