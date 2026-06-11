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
    int k;
    cin >> k;
    string s;
    cin >> s;
    string ans = "";
    if(s.size() > k){
        for(int i = 0; i < k; ++i) ans += s.at(i);
        ans += "...";
    }
    else ans = s;
    cout << ans << endl;
    return 0;
}