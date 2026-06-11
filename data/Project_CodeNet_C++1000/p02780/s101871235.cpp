#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> p(n);
    vector<double> e(n), s(n);
    for(int i = 0; i < n; ++i){
        cin >> p.at(i);
        e.at(i) = (double(p.at(i)) + 1.0) / 2.0;
        if(i != 0) s.at(i) = s.at(i - 1) + e.at(i);
        else s.at(i) = e.at(i);
    }
    double ans = s.at(k - 1);
    for(int i = 0; i < n - k; ++i) ans = max(ans, s.at(i + k) - s.at(i));
    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}