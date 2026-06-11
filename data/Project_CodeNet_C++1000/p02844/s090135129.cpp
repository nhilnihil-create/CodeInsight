#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> note[10];
    for(int i = 0; i < n; i++) {
        note[s[i]-'0'].push_back(i);
    }

    int count = 0;
    for(int i = 0; i < 1000; i++) {
        int a = i / 100;
        int b = (i % 100) / 10;
        int c = i % 10;

        if(note[a].size() == 0) continue;
        int pos = note[a][0];
        auto itr = lower_bound(note[b].begin(), note[b].end(), pos+1);
        if(itr == note[b].end()) continue;
        pos = *itr;
        itr = lower_bound(note[c].begin(), note[c].end(), pos+1);
        if(itr == note[c].end()) continue;
        count++;
    }

    cout << count << endl;
}