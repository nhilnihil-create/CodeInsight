#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    using pint = pair<int, int>; // <人, 0or1>
    vector<vector<pint>> shogen;
    for (int i=0; i<N; i++) {
        int A;
        cin >> A;
        vector<pint> s(A);
        for (int i=0; i<A; i++) {
            cin >> s.at(i).first >> s.at(i).second;
            --s.at(i).first; 
        }
        shogen.push_back(s);
    }
    int res = 0;
    for (int bit=0; bit < (1<<N); bit++) {
        bool isOK = true;
        for (int i=0; i<N; i++) {
            if (!(bit & (1<<i))) continue;
            for (int j=0; j<shogen.at(i).size(); j++) {
                int x = shogen.at(i).at(j).first;
                int y = shogen.at(i).at(j).second;
                if (y == 1 && !(bit & (1<<x))) isOK =  false;
                if (y == 0 && (bit & (1<<x))) isOK = false;
                if (!isOK) break;
            }
            if (!isOK) break;
        }
        if (isOK) {
            int cnt=0;
            for (int i=0; i<N; i++) {
                if (bit & (1<<i)) cnt++;
            }
            res = max(cnt, res);
        }
    }
    cout << res << endl;
}