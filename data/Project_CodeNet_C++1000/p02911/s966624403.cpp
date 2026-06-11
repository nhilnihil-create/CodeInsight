#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vi a(n, 0);
    vi point(n, k);
    //vector<bool> is_win(n, true);
    rep(i, q){
        int tmp;
        cin >> tmp;
        a[tmp-1]++; //勝ち回数
    }

    rep(i, n){
        point[i] -= (q - a[i]);
    }

    rep(i, n){
        if(point[i] > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}