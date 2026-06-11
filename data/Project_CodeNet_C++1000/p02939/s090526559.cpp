#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    string s;
    cin >> s;
    ll ans = s.size();
    for(int i=0;i<s.size();i++){
        //連続する文字数
        ll num=1;
        while(i<s.size()&&s[i] ==s[i+1]){
            num++;
            i++;
        }
        ans -= (num+1)/3;
        //次の文字にくっつけるなら、次の文字はその次の文字と一致しないので飛ばせる。(終端でもloopが終了するだけなので問題なし)
        if((num+1)%3==0){
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}