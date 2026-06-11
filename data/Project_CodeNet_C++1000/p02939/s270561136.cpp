#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    int ans = 1;
    int now = 0;
    string temp = "";
    temp += S.at(0);
    for(int i = 1; i < N; i++) {
        if(i == N - 1 && temp.size() == 1) {
            if(temp.at(0) == S.at(N - 1)) {
                break;
            }
            ans++;
            break;
        }
        if(temp == S.substr(i, 1)) {
            temp = S.substr(i, 2);
            i++;
        } else {
            temp = S.substr(i, 1);
        }
        //cout << i << ':' << temp << endl;
        ans++;
    }
    cout << ans << endl;
    

    return 0;
}