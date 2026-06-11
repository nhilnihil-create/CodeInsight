#include <iostream>
#include <fstream>
#include <algorithm>       // for next_permutation
#include <vector>
#include <queue>
#include <bits/stl_numeric.h>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;


int main()
{
    string s,res;
    cin >> s;
    res = "Yes";
    for(int i = 0; i < s.size(); ++i)
    {
        if(i % 2 == 0 && s[i] != 'h')res = "No";
        if(i % 2 == 1 && s[i] != 'i')res = "No";
    }
    if(s.size() %2 == 1)res = "No";

    cout << res << endl;
}
