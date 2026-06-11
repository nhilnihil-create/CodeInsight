#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N, M;
    cin >> N >> M;
    dsu d = dsu(N);
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        d.merge(a-1, b-1);
    }
    vector<vector<int>> v = d.groups();
    cout << v.size() - 1 << endl;
    return 0;
}