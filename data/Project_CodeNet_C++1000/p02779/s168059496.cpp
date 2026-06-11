#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,flg;

    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    flg = 0;
    rep(i, n-1) {
        if (a[i] == a[i + 1]) {
            //一致あり
            ++flg;
            break;
        }
    }
    //結果
    if (flg>0)
        std::cout << "NO" << endl;
    else
        std::cout << "YES" << endl;
}

