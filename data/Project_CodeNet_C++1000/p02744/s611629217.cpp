#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;

int main() {
    cin >> N;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    map<char, int>mp;
    for (int i = 0; i < 26; i++) {
        mp[alphabet[i]] = i;
    }

    queue<pair<string, int>>que;
    que.push(make_pair("a", 0));

    while (true) {
        string x = que.front().first;
        int a = que.front().second;
        if (x.length() == N) {
            break;
        }
        que.pop();
        for (int i = 0; i <= a+1; i++) {
            if (mp[alphabet[i]] >= a) {
                que.push(make_pair(x+alphabet[i], mp[alphabet[i]]));
            } else {
                que.push(make_pair(x+alphabet[i], a));
            }
        }
    }

    while (!que.empty()) {
        string x = que.front().first;
        que.pop();
        cout << x << endl;
    }
}
