#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,x,y;
    cin >> n >> x >> y;
    int ans[n-1] = {};
    x--;y--;

    int a;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
        a = abs(i-j);
        a = min(a,abs(i-x)+abs(j-y)+1);
        a = min(a,abs(i-y)+abs(j-x)+1);
        if (a > 0) ans[a-1]++;
    }
    for (int ai:ans) cout << ai/2 << "\n";
}