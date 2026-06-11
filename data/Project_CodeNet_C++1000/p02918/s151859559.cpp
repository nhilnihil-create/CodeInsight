#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    n--;
    int ans = 2*k;
    char c, d;
    cin >> c;
    for (int i = 0; i < n; i++){
        cin >> d;
        if (d == c) ans++;
        else c = d;
    }
    cout << min(ans, n) << '\n';
}
