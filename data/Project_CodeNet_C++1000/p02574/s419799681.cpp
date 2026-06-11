// ABC177E.cpp
#include <iostream>
#include <vector>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    else {
        return gcd(y, x % y);
    }
}
int main()
{
    int A = 1000006;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int>count(A);
    rep(i, n) {
        cin >> a.at(i);
        count.at(a.at(i))++;
    }
    bool pairwise = true;
    for (int i = 2; i < A; i++) {
        int cnt = 0;
        for (int j = i; j < A; j += i) {
            cnt += count.at(j);
        }
        if (cnt > 1) pairwise = false;
    }
    if (pairwise) {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    int g = 0;
    rep(i, n) {
        g = gcd(g, a.at(i));
    }
    if (g == 1) {
        cout << "setwise coprime" << endl;
    }
    else {
        cout << "not coprime" << endl;
    }
    return 0;
}
