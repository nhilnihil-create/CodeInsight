#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <fstream>
#include <stdint.h>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define RREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, l, r) for(int i = l; i < r; i++)
#define RFOR(i, l,r) for(int i= (l)-1; i>= (r) ; i--)

template<typename stl>
void show_vec(const stl& x)
{
    for(auto i : x)
        cerr << i << ' ';
    cerr << '\n';
}

void swap_range(vector<int>& dek, int l, int k)
{
    vector<int> ret;
    int r = l + k;
    /* cerr << "l : r" << l  << ':' << r << '\n'; */
    FOR(i, l, r)
    {
        /* cerr << "i:" << i << ' '; */
        ret.push_back(dek[i]);
    }
    /* cerr << "ret1:: " ; show_vec(ret); */
    REP(i, l)
        ret.push_back(dek[i]);
    /* cerr << "ret2:: " ; show_vec(ret); */
    FOR(i, l+k, dek.size())
        ret.push_back(dek[i]);
    /* cerr << "ret3:: " ; show_vec(ret); */
    dek = ret;
}


int main()
{
    ios::sync_with_stdio(false);
    int n, r;
    while(cin >> n >> r)
    {
        if(n == 0)
            return 0;
        vector<int> dek;
        RFOR(i, n+1, 1)
            dek.push_back(i);
        /* show_vec(dek); */
        REP(i, r)
        {
            int p, c;
            cin >> p >> c;
            swap_range(dek, p-1, c);
            /* show_vec(dek); */
        }
        cout << dek[0] << '\n';
    }
}