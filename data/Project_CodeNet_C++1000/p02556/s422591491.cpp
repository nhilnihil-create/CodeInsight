#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> n;
    int mn_x = INT_MAX, mx_x = INT_MIN, mn_y = INT_MAX, mx_y = INT_MIN;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int xx = x + y, yy = y - x;
        mn_x = min(mn_x, xx);
        mx_x = max(mx_x, xx);
        mn_y = min(mn_y, yy);
        mx_y = max(mx_y, yy);
    }

    cout << max(mx_x - mn_x, mx_y - mn_y) << '\n';

    return 0;
}
