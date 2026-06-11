#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    int cnt = 0;
    //3桁のパスワードを000~999まで当て決めする
    rep(i, 1000){
        int key[3] = {i / 100, (i / 10) % 10, i % 10};
        //当て決めした3桁のパスワードの左から何文字目を見るか指定する変数
        int v = 0;
        //3桁のパスワードを作れるような文字の並びが存在するかどうかを調べる
        rep(j, N){
            //パスワードの左からv番目のところと一致する値がSに含まれていれば、見る桁を変える(v++)
            if(S[j] == ('0' + key[v])) v++;
        }
        if(v == 3) cnt++;
    }
    cout << cnt << endl;
    return 0;
}