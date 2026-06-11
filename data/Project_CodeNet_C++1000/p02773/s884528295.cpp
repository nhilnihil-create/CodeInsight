#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    string temp[N];
    map<string, int> voting_paper;
    int ans = 0;

    for(int i = 0; i < N; i++) {
        cin >> temp[i];
        if(voting_paper.count(temp[i])) {
            voting_paper.at(temp[i])++;
            continue;
        }
        voting_paper[temp[i]] = 1;
    }

    for(int i = 0; i < N; i++) {
        ans = max(ans,voting_paper[temp[i]]);
    }
    queue<string> que;
    for(int i = 0; i < N; i++) {
        if(ans == voting_paper[temp[i]]) {
            que.push(temp[i]);
            voting_paper.erase(temp[i]);
        }
    }
    vector<string> list(que.size());
    for(int i = 0; i < list.size(); i++) {
        list.at(i) = que.front();
        que.pop();
    }
    sort(list.begin(),list.end());
    for(int i = 0; i < list.size(); i++) {
        cout << list.at(i) << endl;
    }



    return 0;
}