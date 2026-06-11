/*
ЗАПУСКАЕМ 
░ГУСЯ░▄▀▀▀▄░РАБОТЯГУ░░
▄███▀░◐░░░▌░░░░░░░
░░░░▌░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▌░░░░░▐▄▄░░░░░
░░░░▌░░░░▄▀▒▒▀▀▀▀▄
░░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
░░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░▄▄▌▌▄▌▌░░░░░ 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;

template<class T1, class T2> inline int chkmin(T1 &x, const T2 &y) {
    if (x > y) {
        x = y;
        return 1;
    }
    else {
        return 0;
    }
}

template<class T1, class T2> inline int chkmax(T1 &x, const T2 &y) {
    if (x < y) {
        x = y;
        return 1;
    }
    else {
        return 0;
    }
}

#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);

template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
    while (begin != end) {
        out << (*begin) << " ";
        begin++;
    }
    out << endl;
}

template<class T> void output(const T &x, ostream &out = cerr) {
    output(x.begin(), x.end(), out);
}

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
}


int main() {
    fast_io();
    //read("input");
    int n;
    cin >> n;
    int st = 1;
    while (st < n) {
        st *= 2;
    }
    if (n == st || n <= 2) {
        cout << "No\n";
        exit(0);
    }
    cout << "Yes\n";
    cout << 1 << ' ' << 3 << '\n';
    cout << 3 << ' ' << 2 << '\n';
    cout << 2 << ' ' << n + 1 << '\n';
    cout << n + 1 << ' ' << n + 3 << '\n';
    cout << n + 3 << ' ' << n + 2 << '\n';
    for (int i = 4; i < n; i+= 2) {
        cout << i + 1 << ' ' << i << '\n';
        cout << i << ' ' << 1 << '\n';
        cout << 1 << ' ' << n + i + 1 << '\n';
        cout << n + i + 1 << ' ' << n + i << '\n'; 
    }
    if (n % 2 == 0) {
        cout << n << ' ' << n - 2 << '\n';
        int x = n ^ (n - 2) ^ 1;
        if (x == 3) {
            cout << 3 << ' ' << 2 * n << '\n';
        } else {
            cout << x + n << ' ' << 2 * n << '\n';  
        }
    }
    return 0;
}   
    