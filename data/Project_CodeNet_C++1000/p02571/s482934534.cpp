#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(void){
    string s, t;
    cin >> s >> t;
    int res = 1001;
    for(int i = 0; i < s.size() - t.size() + 1; ++i){
        int tmp = 0;
        for(int j = 0; j < t.size(); ++j){
            if(s[i + j] != t[j]){
                ++tmp;
            }
        }
        res = min(res, tmp);
    }
    cout << res;
    return 0;
}