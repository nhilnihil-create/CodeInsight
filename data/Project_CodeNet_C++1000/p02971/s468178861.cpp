#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    vector<pair<int, int>> cnts;
    REP(i, N)
    {
        cnts.push_back(pair<int, int>(A[i], (int)i));
    }
    sort(cnts.begin(), cnts.end(), [](pair<int, int>& a, pair<int, int>& b){ return a.first > b.first;});
    vector<int> res(N);
    REP(i, N)
    {
        auto it = cnts.begin();
        if (it->second == i)
        {
            ++it;
            res[i] = it->first;
        }
        else
        {
            res[i] = it->first;
        }
        
    }
    REP(i, N)
    {
        cout << res[i] << endl;
    }
    return 0;
}
