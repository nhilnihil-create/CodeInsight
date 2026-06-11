#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,m;

    cin >> n >> m;
    vector<int> ac(n),wa(n);
    rep(i, m) {
        int p;
        string s;
        cin >> p >> s;
        --p;
        if (s == "AC") {
            if (ac[p] == 0)
                ++ac[p];
        }
        else {
            if (ac[p] == 0)
                ++wa[p];
        }
    }
    int seito = 0;
    int pena = 0;
    rep(i, n) {
        if (ac[i] > 0) {
            ++seito;
            pena += wa[i];
        }
    }

    //結果
    std::cout << seito << " " << pena << endl;
}
