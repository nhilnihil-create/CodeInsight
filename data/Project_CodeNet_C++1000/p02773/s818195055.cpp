#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int N;
    cin >> N;
    vector <string> S(N);
    map<string , int> T;
    rep(i , N){
        cin >> S[i];
        T[S[i]]++;
    }
    int maxcnt = 0;
    for (pair<string, int> p: T) {
        if (maxcnt < p.second) {
            maxcnt = p.second;
        }
    }
    vector<string> answer;
    for (pair<string, int> p: T) {
        if (maxcnt == p.second) {
            answer.push_back(p.first);
        }
    }
    sort(answer.begin(), answer.end());
    for (const auto &s: answer) {
        cout << s << endl;
    }
}
