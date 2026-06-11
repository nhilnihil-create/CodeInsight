// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <set>

#define prev asasddlsa
#define rank aljds

using namespace std;

typedef long long ll;

template<typename T>
void print(const vector<T>& s){
    for (auto x : s)
        cout << x << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, d;
    cin >> m >> d;
    int cnt = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 10; j <= d; j++){
            if (j % 10 > 1 && j / 10 > 1 && i == (j % 10) * (j / 10)){
                cnt++;
                // cout << i << " " << j << endl;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}