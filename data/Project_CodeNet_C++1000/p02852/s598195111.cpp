#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    string s;
    cin >> s;

    bool flag = false;
    int cnt = 0;
    for (int i = 0; i <= N ; i++) {
        if (s[i] == '1')
            cnt++;
        else {
            if (cnt >= M) {
                flag = true;
                break;
            }
            cnt = 0;
        }
    }

    if (flag) cout << -1 << endl;
    else {
        vector<int> cost(N + 1, -1);
        int right = N, temp = N;
        int cnt = 1;
        cost[N] = 0;
        for (int i = right; i >= 0; i--) {
            for (int j = 1; j <= min(M,right); j++) {
                if (s[right - j] == '0') {
                    cost[right - j] = cnt;
                    temp = right - j;
                }
            }
            right = temp;
            cnt++;
        }

        int bb = cost[0];
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i <= N; i++) {
            if (cost[i] != -1 && cost[i] == bb - 1) {
                bb--;
                ans.push_back(i);
            }
        }

        for (int i = 1; i < ans.size(); i++)
            cout << ans[i] - ans[i - 1] << " ";
        cout << endl;

    }
    
}

