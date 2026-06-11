#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ll N;
    cin >> N;
    ll temp = N; 
    vector<char> ans;
    ll judge_26 = 0;
    
    //以下26進数判定
    while (1) {
        temp --;
        judge_26 = temp % 26;
        char x = 'a' + judge_26; //数値を文字に
        ans.push_back(x);
        temp /= 26;
        if( temp == 0 ) {
            break;
        }
    }
    
    //配列の中身を逆にする
    reverse ( begin(ans), end(ans) );
    
    //配列の中身を出力する範囲ベースfor文
    for ( auto a: ans ) {
        cout << a;
    }
    cout << endl;
    
    return 0;
}