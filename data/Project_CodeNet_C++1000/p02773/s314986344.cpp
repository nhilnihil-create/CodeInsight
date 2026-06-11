#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n;

    cin >> n;
    vector<string> s(n);
    vector<string> smax(n);
    rep(i, n) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());
    //最大回数取得
    int mx = 0; //最大回数
    int cnt = 0;
    int mcnt = 0;
    rep(i, n-1) {
        if (s[i] == s[i + 1]) {
            //一致
            ++cnt;
            if (cnt > mx) {
                //最大を更新
                mx = cnt;
                smax[0] = s[i];
                mcnt = 0;
            }
            else if (cnt == mx) {
                //最大と同じ
                ++mcnt;
                smax[mcnt] = s[i];
            }
        }
        else {
            //不一致
            cnt = 0;
        }
    }
    //結果
    if (cnt>0)
        rep(i, (mcnt+1)) {
            std::cout << smax[i] << endl;
        }
    else
        rep(i, n) {
        std::cout << s[i] << endl;
    }
}

