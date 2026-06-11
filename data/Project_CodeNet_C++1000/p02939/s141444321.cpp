#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    string S;
    string prev;
    ll count = 0;
    cin >> S;
    for(ll i = 0;i < S.size();i++) {
        for(ll j = i + 1;j < S.size() + 1;j++) {
            string temp = string(S.begin() + i, S.begin() + j);
            if(prev != temp) {
                count++;
                i = j - 1;
                prev = temp;
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}
