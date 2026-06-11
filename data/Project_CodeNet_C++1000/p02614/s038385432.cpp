#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for(int i=0; i<h; ++i)
        cin >> s[i];

    int ans = 0;
    for(int i=0; i<(1<<(h+w)); ++i){
        bitset<32> bs(i);
        int cnt = 0;
        for(int y=0; y<h; ++y){
            for(int x=0; x<w; ++x){
                if(!bs[y] && !bs[h+x] && s[y][x] == '#')
                    ++ cnt;
            }
        }
        if(cnt == k)
            ++ ans;
    }
    cout << ans << endl;

    return 0;
}
