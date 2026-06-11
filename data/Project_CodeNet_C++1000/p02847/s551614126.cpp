#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

double eps = 1e-12;

int main(){
    string s;
    cin >> s;
    map<string, int> mp;
    mp["SUN"] = 7;
    mp["MON"] = 6;
    mp["TUE"] = 5;
    mp["WED"] = 4;
    mp["THU"] = 3;
    mp["FRI"] = 2;
    mp["SAT"] = 1;
    cout << mp[s] << endl;
    return 0;
}
