// タイム: 
// mainは一番下(端的に)

// 場合分けは悪手だということに試行錯誤しながら気づいた
// intでoverflowしててこづった

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int64_t calcNum (int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t ac, ad, bc, bd;
    ac = a * c;
    ad = a * d;
    bc = b * c;
    bd = b * d;
    return max(max(max(ac, ad), bc), bd);
}


int main() {
    int64_t a,b,c,d;
    cin >> a >> b >> c >> d;
    int64_t result = calcNum(a, b, c, d);
    cout << result << endl; 
}
