#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<V<P<int, int> > > v(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v[i].resize(a);
        for(int j = 0; j < a; j++){
            int x, y; cin >> x >> y;
            x--;
            v[i][j] = make_pair(x, y);
        }
    }

    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(bit & (1 << i)){
                for(int j = 0; j < (int)v[i].size(); j++){
                    int f = v[i][j].first;
                    int s = v[i][j].second;
                    int b = bit & (1 << f);
                    if(b && s) continue;
                    if(b == 0 && s == 0) continue;
                    else{
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        if(flag){
            bitset<15> bs(bit);
            int tmp = bs.count();
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}
