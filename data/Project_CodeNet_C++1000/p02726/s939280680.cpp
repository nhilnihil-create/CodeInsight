#include<bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

using ll = long long;
const int N = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(0);

    int n,x,y;
    cin >> n >> x >> y;
    map<int,int> cnt;
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            int no_edge = j-i;
            int pp = abs(x-i) + abs(y-j) + 1;
            cnt[min(no_edge, pp)]++;
        }
    }
    for(int i = 1; i < n; ++i)
        cout << cnt[i] << "\n";
    return 0;
}
