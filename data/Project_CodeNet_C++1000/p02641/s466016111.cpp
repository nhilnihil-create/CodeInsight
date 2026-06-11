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
    int x, n, p, dif;
    cin >> x >> n;
    vector<int> forb(102);
    for(int i = 0; i < n; ++i){
        cin >> p;
        forb.at(p) = 1;
    }
    pair<int, int> ans(999, -1);
    for(int i = 0; i < 102; ++i){
        if(forb.at(i) == 1) continue;
        else{
            dif = abs(x - i);
            pair<int, int> p(dif, i);
            ans = min(ans, p);
        }
    }
    cout << ans.second << endl;
    return 0;
}