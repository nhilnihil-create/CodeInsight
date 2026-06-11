#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>

#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    cin >> S;
    vector<int> ret(S.size());

    int numR = 0;
    rep(i, S.size()) {
        if(S[i] != 'R') {
            continue;
        }
        numR++;
        if(S[i+1] == 'R') {
            continue;
        }
        ret[i] = (numR + 2 - 1) / 2;
        ret[i+1] = (numR / 2);
        numR = 0;
    }

    int numL = 0;
    for(int i = S.size() - 1; i >= 0; --i) { 
        if(S[i] != 'L') {
            continue;
        }
        numL++;
        if(S[i-1] == 'L') {
            continue;
        }
        ret[i]   += (numL + 2 -1) / 2;
        ret[i-1] += (numL / 2);
        numL = 0;
    }

    rep(i, S.size()) {
        cout << ret[i] << " ";
    }
    cout << endl;

    return 0;
}
