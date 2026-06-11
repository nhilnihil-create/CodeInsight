#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

int main() {
    int X,N;
    cin >> X >> N;
    vector<bool> ok(102);
    rep(i,102) ok[i] = true;
    rep(i,N){
        int p;
        cin >> p;
        ok[p] = false;
    }
    if(ok[X]){
        cout << X << endl;
        return 0;
    } 
    int i,j;
    i = X-1;
    j = X+1;
    while(1){
        if(ok[i]){
            cout << i << endl;
            return 0;
        }
        if(ok[j]){
            cout << j << endl;
            return 0;
        }
        i--;
        j++;
    }
}
