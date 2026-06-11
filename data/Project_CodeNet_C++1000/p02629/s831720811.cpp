#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll N;
    cin >> N;
    ll num = 26;
    string S = "";
    //26進数の各桁の値を求める処理
    while(N > 0){
        //辻褄合わせのために１を引く
        N--;
        //26による剰余をその桁のアルファベットとしてＳに加える
        S += (char)('a' + (N % num));
        //26で割ることによって次の桁に移動する
        N /= num;
    }
    //格納順番が、逆向きなので、reverseする
    reverse(S.begin(), S.end());
    cout << S << endl;
    return 0;
}