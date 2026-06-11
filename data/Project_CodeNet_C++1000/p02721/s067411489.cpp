#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)
#define REP(i, n) FOR((i), 0, (n))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T>
void print_container(T &container, string delim=" ") {
    bool first = true;
    for(auto &t: container){
        if(!first){
            cout << delim;
        }
        first = false;
        cout << t;
    }
    cout << endl;
}

int main() {
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> greed_front;
    vector<int> greed_back;
    int cnt = 0;
    REP(i, n){
        if(s[i] == 'o'){
            greed_front.push_back(i);
            cnt++;
            if(cnt == k)
                break;
            i += c;
        }
    }
    cnt = 0;
    RFOR(i, n-1, 0){
        if(s[i] == 'o'){
            greed_back.push_back(i);
            cnt++;
            if(cnt == k)
                break;
            i -= c;
        }
    }
    reverse(greed_back.begin(), greed_back.end());

    vector<int> ans;
    REP(i, k){
        if(greed_front[i] == greed_back[i])
            ans.push_back(greed_front[i]+1);
    }


    for(auto t: ans)
        cout << t << endl;

    return 0;
}