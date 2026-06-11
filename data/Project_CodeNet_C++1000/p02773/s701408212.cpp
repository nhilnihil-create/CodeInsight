#include <bits/stdc++.h>
using namespace std;

// C - Poll
// 途中
int main() {
    int N;
    cin >> N;
    map<string, int> betMap;
    string S;
    int maxCount = 0;
    for (int i = 0; i < N; i++) {
        cin >> S;
        betMap[S]++;
        maxCount = max(betMap[S], maxCount);
    }

    vector<string> maxBetList;
    for (auto bet : betMap){
        if (bet.second == maxCount) {
            maxBetList.push_back(bet.first);
        }
    }
    sort(maxBetList.begin(), maxBetList.end());

    for (auto bet : maxBetList) {
        cout << bet << endl;
    }

}
