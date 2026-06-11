#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> tele(n + 1);
    for (int i = 1; i <= n; i++) cin >> tele.at(i);
    vector<int> dis(n + 1, -1);
    dis.at(1) = 0;
    int loop, T = 0, town = 1, ans = 1;
    while(1) {
        town = tele.at(town);
        T++;
        if (dis.at(town) >= 0) {
            loop = town;
            T -= dis.at(loop);
            break;
        }
        dis.at(town) = T;
    }

    if (k < dis.at(loop)) for (int i = 0; i < k; i++) ans = tele.at(ans);
    else {
        k -= dis.at(loop);
        k %= T;
        ans = loop;
        for (int i = 0; i < k; i++) ans = tele.at(ans);
    }
    
    cout << ans << endl;
}