#include <iostream>
#include <set>
#include <iterator>
#include <utility>
using namespace std;

int q[100001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, p;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> p;
        q[p] = i;
    }

    set <int> myset;
    myset.insert(-1); myset.insert(0); myset.insert(n+1); myset.insert(n+2);

    set <int> :: iterator it;
    int i, j;
    long long a, b, c, d, x, y;
    long long ans = 0;
    for (i = n; i > 0; i--){
        j = q[i];
        it = myset.insert(j).first;
        b = *(--it); a = *(--it);
        ++it; ++it;
        c = *(++it); d = *(++it);
        x = (a == -1) ? 0 : (c - j)*(b - a);
        y = (d == n+2) ? 0 : (d - c)*(j - b);
        ans += (x + y) * i;
    }
    cout << ans << '\n';

}
