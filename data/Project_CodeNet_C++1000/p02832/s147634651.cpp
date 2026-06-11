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
    int n, ans = 0, cnt = 1, one = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
        if(a.at(i) == 1) one++;
    }
    if(one == 0) ans = -1;
    else{
        for(int i = 0; i < n; ++i){
            if(a.at(i) == cnt) cnt++;
            else ans++;
        }
    }
    cout << ans << endl;
    return 0;
}