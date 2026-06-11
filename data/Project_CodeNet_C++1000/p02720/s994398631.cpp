#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll k;
    string ans;
    cin >> k;
    queue<string> que;
    for(int i = 1; i <= 9; i++){
        que.push(to_string(i));
    }

    ll cnt = 1;
    while(true){
        if(cnt == k){
            ans = que.front();
            break;
        } else {
            if(que.front().back() != '0'){
                que.push(que.front() + to_string((que.front().back() - '0') - 1));
            }
            que.push(que.front() + to_string((que.front().back() - '0')));
            if(que.front().back() != '9'){
                que.push(que.front() + to_string((que.front().back() - '0') + 1));
            }
            que.pop();
        }
        cnt++;
    }
    cout << ans << endl;
    return 0;
}
