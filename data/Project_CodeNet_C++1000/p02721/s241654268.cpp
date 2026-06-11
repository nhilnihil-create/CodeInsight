#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main() {
    lint n, k, c;
    cin >> n >> k >> c;

    string s;
    cin >> s;

    vector<lint> left;
    for(lint i=0; i<n; i++) {
        if(left.size() >= k) break;
        if(s[i] == 'x') continue;
        left.push_back(i);
        i+=c;
    }

    vector<lint> right;
    for(lint i=n-1; i>=0; i--) {
        if(right.size() >= k) break;
        if(s[i] == 'x') continue;
        right.push_back(i);
        i-=c;
    }
    reverse(right.begin(), right.end());

    for(lint i=0; i<left.size(); i++) {
        if(left[i] == right[i]) cout << left[i]+1 << endl;
    }
}