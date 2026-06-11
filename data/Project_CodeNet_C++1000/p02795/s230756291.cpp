#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <cmath>
#include <climits>

typedef long long ll;
using namespace std;

ll MOD = 1e9+7;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int ans = 0;
    if(h > w){
        int moves = 0;
        while(moves < n){
            moves += h;
            ans++;
        }
    }
    else{
        int sum = 0;
        while(sum < n){
            sum += w;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}