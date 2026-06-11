#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;
using boost::sort;
using boost::adaptors::reversed;

int main() {
    string t;
    cin >> t;
    for (int i = 0; i < (int)t.length(); i++) {
        if (t[i] == '?') t[i] = 'D';
    }

    cout << t << endl;
}
