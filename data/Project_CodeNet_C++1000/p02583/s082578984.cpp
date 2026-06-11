#include <iostream>
using namespace std;

int n, a[128], ans;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            for(int k = j+1; k <= n; k++)
                if(a[i]!=a[j] && a[j]!= a[k] && a[i] != a[k] && a[i]+a[j] > a[k] && a[i]+a[k] > a[j] && a[j]+a[k] > a[i])
                    ans++;
    cout << ans;
}
