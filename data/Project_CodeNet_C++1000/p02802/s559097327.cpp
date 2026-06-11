#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;
using ll = long long;

int main()
{
    int n,m; cin >> n >> m;
    vector<int> prob(n+1,0); // 問題nをACしたかメモする配列
    string tmps;
    int tmp;
    vector<int> x(n+1); // 初めてACするまでにWAした回数。
    rep(i,m) {
        cin >> tmp >> tmps;
        if(tmps == "AC") prob[tmp] = 1; // 問題tmpがACだったらACしたかメモする配列probにメモ
        else {
            if (prob[tmp] == 0) { // ACしていない問題でWAだった場合ペナルティを配列xに加算
                x[tmp]++;
            }
        }
    }
    int ansc = 0, ansp = 0;
    rep(i,n+1) {
        if(prob[i] == 0) x[i] = 0; // prob[i] == 0つまり問題iをACしていなかったらその問題のペナルティをリセット
        
        ansc += prob[i];
        ansp += x[i];
    }

    cout << ansc << " " << ansp << endl;
}