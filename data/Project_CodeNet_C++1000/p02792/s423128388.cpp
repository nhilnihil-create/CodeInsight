#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;



int top(int n){
    int t = n%10;
    while(n>0){
        n /= 10;
        if(n>0) t = n%10;
    }
    return t;
}
int main(){
    int n;
    cin >> n;
    int table[9][9];
    rep(i,9)rep(j,9) table[i][j] = 0;
    for(int i = 1;i<=n;i++){
        int x,y;
        x = top(i);
        y = i%10;
        --x;--y;
        //cout << x <<" " << y<< endl;
        if(x == -1 || y == -1) continue;
        table[x][y]++;
    }

    // rep(i,9)rep(j,9){
    //     cout << "i " <<i<<" j "<<j<<endl;
    //     cout << table[i][j]<<endl;
    // }
    //cout << table[0][0] << endl;
    ll ans = 0;
    rep(i,9)rep(j,9){
        if(i==j) ans += table[i][j]*table[i][j];
        else  ans += table[i][j]*table[j][i];
    }

    cout << ans << endl;
 }