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
    string s , t, ans;
    cin >> s >> t;
    for(int i = 0; i < n; ++i){
        ans += s.at(i);
        ans += t.at(i);
    }
    cout << ans << endl;
    return 0;
}