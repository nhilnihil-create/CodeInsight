#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; string S;
    cin >> N >> S;

    for(int i=0; i<S.size(); i++) {
        int c = (int)(S[i]-'A');
        if(c + N >= 26) c -= 26;
        int n = 'A' + c + N;
        cout << char(n);
    }
}