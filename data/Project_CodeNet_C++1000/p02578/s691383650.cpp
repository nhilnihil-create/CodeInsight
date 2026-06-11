#include <iostream>

using namespace std;
const int N = 2e5 + 1;
int a[N] , n;
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 2; i <= n; i++)
        if (a[i - 1] > a[i]) ans = ans + (a[i - 1] - a[i]) , a[i] = a[i - 1];
    cout << ans;
}