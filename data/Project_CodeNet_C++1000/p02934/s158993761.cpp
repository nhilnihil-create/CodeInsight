#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    double count;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count += 1.0/a[i];
    }

    double ans = 1.0/count;

    cout << setprecision(16) << ans << endl;
    
    return 0;
}