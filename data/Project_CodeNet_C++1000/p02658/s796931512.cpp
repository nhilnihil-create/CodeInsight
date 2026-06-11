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
    int n;
    cin >> n;
    long long ans = 1;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
        if(a.at(i) == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; ++i){
        if(a.at(i) > 1000000000000000000 / ans){
            ans = -1;
            break;
        }
        ans *= a.at(i);
    }
    cout << ans << endl;
    return 0;
}