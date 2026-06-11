#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

int main(){
    string s; cin >> s;

    stack<int> st1;
    stack<pair<int,int>> st2;

    int sum = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '\\'){
            st1.push(i);
        }
        else if(s[i] == '/' && st1.size()>0){
            int j = st1.top(); st1.pop();
            sum += i-j;
            int a = i-j;
            while(st2.size()>0 && st2.top().first > j){
                a += st2.top().second; st2.pop();
            }
            st2.push({j, a});
        }
    }

    // 出力
    vector<int> ans;
    while(st2.size() > 0){
        ans.push_back(st2.top().second);
        st2.pop();
    }
    reverse(ans.begin(), ans.end());

    cout << sum << endl;
    cout << ans.size();
    for(int i=0; i<ans.size(); i++) cout << " " << ans[i];

    cout << endl;
    return 0;
}
