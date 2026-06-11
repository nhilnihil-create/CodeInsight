#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    vector<char> T(N);
    for(int i = 0; i < N; i++) {
        cin >> T.at(i);
    }
    map<char, int> Points{{'r', R}, {'s', S}, {'p', P}};
    map<char, char> my_hands{{'r', 'p'}, {'s', 'r'}, {'p', 's'}};
    vector<char> ls(N);
    for(int i = 0; i < N; i++) {
        if(i < K) {
            ans += Points.at(my_hands.at(T.at(i)));
            ls.at(i) = my_hands.at(T.at(i));
        } else if(my_hands.at(T.at(i)) != ls.at(i - K)) {
            ans += Points.at(my_hands.at(T.at(i)));
            ls.at(i) = my_hands.at(T.at(i));
        }
    }
    cout << ans << endl;
}