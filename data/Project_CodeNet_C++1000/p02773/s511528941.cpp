#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
    if (a.first < b.first) {
        return false;
    } else if (b.first < a.first) {
        return true;
    } else {
        return a.second < b.second;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> appear_map;
    vector<pair<int, string>> appear;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (appear_map.find(s) != appear_map.end()) {
            appear_map[s]++;
        } else {
            appear_map[s] = 1;
        }
    }
    for (map<string, int>::iterator it = appear_map.begin(); it != appear_map.end(); it++) {
        appear.push_back( make_pair(it->second, it->first) );
    }
    sort(appear.begin(), appear.end(), comp);
    int biggest_no = appear[0].first;
    for (int i = 0; i < n; i++) {
        if (appear[i].first == biggest_no) {
            cout << appear[i].second << '\n';
        } else {
            break;
        }
    }
}