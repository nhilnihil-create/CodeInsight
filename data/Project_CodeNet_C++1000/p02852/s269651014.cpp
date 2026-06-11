#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int N,M;
    string S;
    cin >> N >> M >> S;
    int now = N;
    vector<int> ans;
    while (now > 0){
        bool flag = true;
        for (int step=M;step>0;step--){
            if (!flag) continue; 
            if (now - step < 0 || S[now - step] == '1') continue;
            ans.push_back(step);
            now -= step;
            flag = false;
        }
        if (flag == true) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << endl;
    }

    return 0;
}