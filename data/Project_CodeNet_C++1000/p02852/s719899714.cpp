#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int N, M;
    string S;
    cin >> N >> M >> S;
    reverse(S.begin(), S.end());

    int now = 0;
    vector<int> ans;
    while(now != N) {
        bool flag = false;
        for(int i=M; i; i--) {
            if(now + i > N) continue;
            if(S[now+i] == '0') {
                now += i;
                ans.push_back(i);
                cerr << i << endl;
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << -1 << endl;
            return 0;
        }
    }

    reverse(ans.begin(), ans.end());
    for(auto e: ans) {
        cout << e << ' ';
    }
    return 0;
}
