#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    string s,t,u;
    cin >> s;
    int q;
    cin >> q;
    int flag= 0;
    rep(i,q){
        int a,f;
        char c;
        cin >> a;
        if(a==1) flag++;
        else{
            cin >> f >> c;
            if((f+flag)%2==1) t += c;//先頭に追加
            else u += c; //末尾に追加
        }
    }
    reverse(t.begin(),t.end());
    string ans = t+s+u;
    if(flag%2) reverse(ans.begin(),ans.end());
    cout << ans << endl;
}