#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n, m, q; cin >> n >> m >> q;
    int data[q][4]; rep(i,q) rep(j,4) cin >> data[i][j];

    int num[n+m-1]; rep(i,n+m-1) num[i] = i+1;
    int ans = 0;
    // サイズnの部分集合を列挙
    for(int bit=(1<<n)-1; ; ){
        vector<int> data2;
        for(int i=0; i < (n+m-1); i++){
            if(bit & (1<<i)){
                int j = data2.size();
                data2.push_back(i-j+1);
            }
        }
        int count = 0;
        rep(i,q){
            if(data2[data[i][1]-1] - data2[data[i][0]-1] == data[i][2]) count += data[i][3];
        }
        ans = max(ans, count);
        // 次のbit
        int x = bit & -bit, y = bit + x;
        bit = (((bit & ~y)/x)>>1)|y;
        if(bit >= (1<<(n+m-1))) break;
    }
    cout << ans << endl;
}