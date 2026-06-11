#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<vector<ll>> DP;

char win(char t) {
    char w;
    if (t == 'r') w = 'p';
    else if (t == 's') w = 'r';
    else if (t == 'p') w = 's';
    return w;
}

int main() {
    ll N, K; cin >> N >> K;
    ll R, S, P; cin >> R >> S >> P;
    string T; cin >> T;
    string hand;

    map<char,int> bonus;
    bonus['r'] = R;
    bonus['s'] = S;
    bonus['p'] = P;
    
    ll score = 0;
    for (int i = 0; i < N; i++) {
        char t = T[i];
        char w = win(t);
        if (i >= K && hand[i - K] == w) { // if you can't win
            if (i + K < N) { // There's future fight
                w = win(T[i+K]); // i+K'th turn's winning hand
                if (t == w) t = T[i+K]; // if t shouldn't be used, change
            }
            hand.push_back(t);
            continue;
        } 
        score += bonus[w];
        hand.push_back(w);
    }

    cout << score << endl;
}
