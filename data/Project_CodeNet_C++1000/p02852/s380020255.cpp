#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 9 3
// 0001000100
int main(){
    int n, step_len;
    cin >> n >> step_len;
    string sugoroku;
    cin >> sugoroku;
    stack<int> ans;
    int last_len = 0;
    int len_max = 0;
    for (int i = n-1; i > -1; --i){
        len_max++;
        if (len_max > step_len){
            if (last_len == 0){
                cout << -1 << endl;
                return 0;
            } else {
                ans.push(last_len);
                len_max -= last_len;
                last_len = 0;
            }
        }
        if (sugoroku[i] == '0'){
            last_len = len_max;
        }
        if (i == 0){
            ans.push(last_len);
        }
    }
    while (!ans.empty()) {
        printf("%d ", ans.top());
        ans.pop();
    }
    return 0;
}