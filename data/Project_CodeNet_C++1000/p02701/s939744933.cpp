#include <bits/stdc++.h>
using namespace std;

int N;
string str;
map<string, int> m;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin >> N;
    while(N--) {
        cin >> str;
        m[str]++;
    }
    cout << m.size();
}