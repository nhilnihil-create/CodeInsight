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
    int n, mx = 0, mn = 1010;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; ++i){
        cin >> x.at(i);
        mx = max(mx, x.at(i));
        mn = min(mn, x.at(i));
    } 
    int ans = 10101010; 
    for(int j = mn; j <= mx; ++j){
        int len = 0;
        for(int i = 0; i < n; ++i){
            len += (x.at(i) - j) * (x.at(i) - j);
        }
        ans = min(ans, len);
    }
    cout << ans << endl;
    return 0;
}