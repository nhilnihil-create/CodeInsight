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
    char s, ans;
    string a = "abcdefghijklmnopqrstuvwxyz";
    cin >> s;
    for(int i = 0; i < 26; ++i){
        if(a.at(i) == s) ans = a.at(i + 1);
    }
    cout << ans << endl;
    return 0;
}