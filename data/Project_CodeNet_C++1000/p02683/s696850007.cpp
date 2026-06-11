#include <bits/stdc++.h>

using namespace std;

bool skill(vector<long>& scores, long m, long x) {
    for (int i = 0; i < m; i++) {
        if (scores[i] < x) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n, m, x;
    cin >> n >> m >> x;
    vector<vector<long>> books;
    vector<long> scores(m+1,0);
    long c;
    for (int i = 0; i < n; i++) {
        books.push_back(vector<long>());
        cin >> c;
        books[i].push_back(c);
        scores[0] += c;
        for (int j = 0; j < m; j++) {
            cin >> c;
            books[i].push_back(c);
            scores[j+1] += c;
        }
    }
    for (int i = 0; i < m; i++) {
        if (scores[i+1] < x) {
            cout << -1;
            return 0;
        }
    }
    long cost = scores[0];
    for (int i = 0; i < pow(2,n); i++) {
        long total = 0;
        vector<long> scorew(m,0);
        for (int j = 0; j < n; j++) {
            if (((i >> j) & 1) == 0) {
                total += books[j][0];
                for (int k = 0; k < m; k++) {
                    scorew[k] += books[j][k+1];
                }
            
            }
        }
        if (skill(scorew,m,x)) {
            if (total < cost) {
                cost = total;
            }
        }
    }
    cout << cost;   
}
