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
    int k, x;
    cin >> k >> x;
    string ans = "No";
    if(500 * k >= x) ans = "Yes";
    cout << ans << endl;
    return 0;
}