#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <cstring>
#include <cmath>
#include <tuple>
#include <complex>
#include <bitset>
#include <climits>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using pii = pair<int, int>;
using pll = pair<LL, LL>;
using pld = pair<LD, LD>;
int N, M, Q;
int max_score = 0;
vector<int> A;
vector<array<int, 4>> quadruples;


void solve(const int beg_nr, const int n, const int k)
{
    if (k == 0)
    {
        int cur_score = 0;
        for (const array<int, 4> &quadruple : quadruples)
        {
            const int &a = quadruple[0] - 1, &b = quadruple[1] - 1, &c = quadruple[2], &d = quadruple[3];

            if (A[b] - A[a] == c)
            {
                cur_score += d;
            }
        }

        max_score = max(max_score, cur_score);
        
        /*cerr << "A: ";
        for (auto &z : A)
        {
            cerr << z << " ";
        }
        cerr << endl;*/
        return;
    }

    for (int j = beg_nr; j <= M; ++j)
    {
        A.emplace_back(j);
        solve(j, n, k - 1);
        A.pop_back();
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> Q;
    quadruples.resize(Q);
    for (array<int, 4> &quadruple : quadruples)
    {
        for (int i = 0; i < 4; ++i)
        {
            cin >> quadruple[i];
        }
    }

    solve(1, N + M - 1, N);

    cout << max_score;
}
