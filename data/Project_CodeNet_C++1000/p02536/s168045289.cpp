#include <bits/stdc++.h>
#include <atcoder/all>
// $ g++ main.cpp -std=c++14 -I .
// https://atcoder.github.io/ac-library/document_ja/
using namespace std;
using namespace atcoder;

int main(){
    int n, m;
    cin >> n >> m;
    dsu d(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        d.merge(--a, --b);
    }
    cout << (d.groups().size() - 1) << endl;
}