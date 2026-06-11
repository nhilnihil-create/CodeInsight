#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long> a(4);
    for (long long &x : a) cin >> x;
    long long ans = -1e18;
    for (int i = 0; i < 2; i++){
        for (int j = 2; j < 4; j++){
            long long temp = a[i] * a[j];
            ans = temp > ans ? temp : ans;
        }
    }
    cout << ans << endl;
    return 0;
}
