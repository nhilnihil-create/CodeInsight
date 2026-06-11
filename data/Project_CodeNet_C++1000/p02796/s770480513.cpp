#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>

#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int x, l;
    vector<P> v(n);

    for(int i = 0; i < n; i ++) {
        cin >> x >> l;
        v[i] = make_pair(x+l, x-l);
    }
    sort(v.begin(), v.end());

    int count = 1;
    int now = 0;
    for (int i = 1; i < n; i ++) {
        if (v[now].first <= v[i].second) {
            count ++;
            now = i;
        }
    }

    cout << count << endl;
    return 0;
}