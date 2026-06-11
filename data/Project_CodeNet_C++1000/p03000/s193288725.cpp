#include <cstdio>
#include <cmath>
#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdint>
#include <functional>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;

const ll mod = 1000000000 + 7; //10^9


int main() {
    int N, X;
    cin >> N >> X;
    vector<int> D(N+1);
    vector<int> L(N);
    D[0] = 0;
    for (auto &&i : L)
    {
        cin >> i;
    }
    for (int i = 0; i < N; i++)
    {
        D[i + 1] = D[i] + L[i];
    }
    int ans = 0;
    
    for (int i = 0; i < N + 1; i++)
    {
        if(D[i] <= X) ans++;
    }
    cout <<  ans << endl;
    
}