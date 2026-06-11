#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N, M;
    bool flag = false;
    vector<string> ids;
    cin >> N;
    for(int i=0; i<N; i++) {
        string s;
        cin>>s;
        ids.push_back(s);
    }

    cin >> M;
    for(int i=0; i<M; i++) {
        string s;
        cin >> s;
        auto result = find(ids.begin(), ids.end(), s);
        if(result == ids.end()) {
            cout << "Unknown " << s << endl;
        } else {
            flag = !flag;
            if(flag) cout << "Opened by " << *result << endl;
            else cout << "Closed by " << *result << endl;
        }
    }
    return 0;
}

int main() {
    return solve();
}

