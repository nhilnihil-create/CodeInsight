#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n; 
    long long int a[n+1];
    long long int b[n];

    for (int i = 0; i < n+1; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    long long int ans = 0;

    for (int i = 0; i < n; i++) {
        int left = min(a[i], b[i]);
        ans += left;
        a[i] -= left;
        b[i] -= left;

        int right = min(a[i+1], b[i]);
        ans += right;
        a[i+1] -= right;
        b[i] -= right;

    }

    cout << ans << endl;
    
}