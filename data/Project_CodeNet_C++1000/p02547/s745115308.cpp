#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int maxn = 1e5 + 5;
int main()
{
    ios::sync_with_stdio(false);
    int n ; cin >> n;
    int cnt = 0, maxx = 0;
    for (int i = 1 ; i <= n ; i++){
        int x , y; cin >> x >> y;
        if (x == y) cnt++;
        else cnt = 0;
        maxx = max(maxx , cnt);
    }
    if (maxx >= 3) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
