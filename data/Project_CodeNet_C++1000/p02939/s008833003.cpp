#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int N = S.size();
    
    int ans = 0;

    // 直前が1文字だったかのフラグ
    bool one = false;
    // 今から見るインデックス
    int pt = 0;
    
    while(pt < N){
        // 残り2文字でその2文字が同じなら特別ルール適用
        if(pt == N-2 && S[pt] == S[pt+1]){
            ans++;
            break;
        }
        // 1文字で取れないなら2文字、取れるなら1文字で取る
        if(one && S[pt] == S[pt-1]){
            ans++;
            pt += 2;
            one = false;
        }else{
            ans++;
            pt++;
            one = true;
        }
    }
    
    cout << ans << endl;
    return 0;
}
