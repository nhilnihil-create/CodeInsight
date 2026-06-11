#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >

using namespace std;

typedef long long lint;

void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    string S, T;
    cin >> S >> T;
    map<char, vector<int> > index;
    for (int i = 0;i < S.size(); i++) {
        index[S[i]].push_back(i);
    }

    lint i = 0;
    for (char c : T) {
        if (index[c].empty()) {
            cout << -1 << endl;
            return 0;
        }

        int n = S.size();
        int pos = lower_bound(ALL(index[c]), (int)(i % n)) - BEGIN(index[c]);
        if (pos == index[c].size()) {
            i = i + n - i % n + index[c][0] + 1;
        } else {
            i += index[c][pos] - i % n + 1;
        }
    }

    cout << i << endl;
    return 0;
};
