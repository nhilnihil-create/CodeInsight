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
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for(int i = 2; i < n; ++i){
        if(s.at(i - 2) == 'A' && s.at(i - 1) == 'B' && s.at(i) == 'C') ans++;
    }
    cout << ans << endl;
    return 0;
}