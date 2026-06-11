#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int fact2(int n) {
    int result = 0;
    while (n > 0) {
        result += n/2;
        n /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    string str;
    cin >> str;
    for (int i = 1; i < N; i++) v.push_back(abs(str[i] - str[i-1]));
    N--;
    
    int cntOne = 0;
    int isOdd = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] == 1) {
            cntOne++;
            if (fact2(N-1) == fact2(i) + fact2(N-1-i)) isOdd ^= 1;
        }
    }
    if (isOdd) cout << 1 << "\n";
    else if (cntOne > 0) cout << 0 << "\n";
    else {
        int isOdd = 0;
        for (int i = 0; i < N; i++) {
            if (v[i] == 2) {
                if (fact2(N-1) == fact2(i) + fact2(N-1-i)) isOdd ^= 1;
            }
        }
        if (isOdd) cout << 2 << "\n";
        else cout << 0 << "\n";
    }
}
