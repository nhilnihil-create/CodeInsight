#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<int> a(N+1, 0);
    //iの書かれた箱に入れるボールの個数（0 or 1）
    vector<int> b(N+1, 0);
    for(int i = 1; i < N+1; i++) cin >> a[i];

    for(int i = N; i >= 1; i--){
        //iの倍数の箱に入っているボールの総数
        int sum = 0;
        //自分(i)より大きなiの倍数が存在するならば、それらの箱に入っているボールの総数を見る
        for(int j = i+i; j <= N; j+=i){
            sum ^= b[j];
        }
        //sum = 0, a[i] = 1の場合にb[i] = 1が格納される。
        //sum = 1, a[i] = 0の場合は問題設定的に考えられない
        //sum = 1 && a[i] = 1 または、sum = 0, a[i] = 0の時にb[i] = 0が格納される
        b[i] = sum ^ a[i];
    }
    vector<int> ans;
    //b[i]に1が入っている場合は、その箱の番号(i)を答えを出力するための配列ansに格納
    for(int i = 1; i < N+1; i++){
        if(b[i]) ans.push_back(i);
    }
    //答えを出力
    cout << (int)ans.size() << endl;
    rep(i, (int)ans.size()) cout << ans[i] << endl;
    return 0;
}