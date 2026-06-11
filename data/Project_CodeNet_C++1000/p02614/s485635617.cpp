#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int h , w, k;
    cin >> h >> w >> k;
    string s[h];
    for(int i=0;i<h;i++) cin >> s[i];
    int ans = 0;
    int maki = 1 << h;
    int niko = 1 << w;
    for(int bit1 = 0; bit1 < maki ; bit1++){
      for(int bit2 = 0; bit2 < niko ; bit2 ++){
        int cnt = 0;
        for(int i=0;i<h;i++){
          for(int j=0;j<w;j++){
            if(s[i][j] == '#' && !(bit1 >> i & 1 || bit2 >> j & 1)) cnt++;
          }
        }
        if(cnt == k) ans++;
      }
    }
    cout << ans << endl;
    return 0;
}
