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
    string s;int ans;
    cin >> s;
    vector<string> a={"SAT","FRI","THU","WED","TUE","MON","SUN"};
    for(int i = 0; i < 7; ++i) if(s== a.at(i)) ans = i + 1;
    cout << ans << endl;
    return 0;
}