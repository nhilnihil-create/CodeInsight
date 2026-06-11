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
    int n; string s, ans = "";
    cin >> n >> s;
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < s.size(); ++i){
        for(int j = 0; j < 26; ++j){
            if(s.at(i) == a.at(j)){
                ans += a.at(j + n);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}