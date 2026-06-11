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
    vector<int> p(n);
    for(int i = 0; i < n; ++i) cin >> p.at(i);
    int mn = 1010101, ans = 0;
    for(int i = 0; i < n; ++i){
        mn = min(mn, p.at(i));
        if(mn == p.at(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}