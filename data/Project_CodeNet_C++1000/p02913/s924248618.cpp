#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define DIV 1000000007
using namespace std;
using ll = long long;

vector<int> zalgo(string &T) {
    int N = T.size();
    vector<int> Z(N);

    Z[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i + j < N && T[i + j] == T[j])j++;
        Z[i] = j;

        if (j == 0) { i++; continue; }

        int k = 1;
        while (k + Z[k] < j && i + k < N) {
            Z[i + k] = Z[k];
            k++;
        }
        
        i += k;
        j -= k;

    }

    return Z;
}


int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        string T = s.substr(i);
        auto z = zalgo(T);

        for (int j = 0; j < T.size(); j++) {
            int len = min(j, z[j]);
            ans = max(ans, len);
        }
    }

    cout << ans << endl;

}
