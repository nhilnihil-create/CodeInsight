#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
int main() {
    long long H, W;
    cin >> H >> W;
    long long ans ;
    if((H==1)||(W==1)){
        ans= 1;
    }
    else{
            // 1
        if((H%2==0)&&(W%2==0)){
            ans = (H*W/2) ;
        }
        // 2
        else if((H%2==1)&&(W%2==0)){
            ans = (H-1)*(W/2);
            ans = ans + W/2;
        }
        // 3
        else if((H%2==0)&&(W%2==1)){
            ans = (H/2)*(W-1);
            ans = ans + H/2;
        }
        // 4
        else {
            ans = ((H-1)/2)*(W-1);
            ans = ans + (H-1)/2 ;
            ans = ans + (W-1)/2 ;
            ans = ans + 1;
        }
    }
    cout << ans << endl;
}