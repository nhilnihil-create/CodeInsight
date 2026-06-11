#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

/*
using PAIR = pair<string, int>;
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA() cerr << "AAAAA" << endl
#define debug_() cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;

using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int n;
    // cin >> n;
    string s;
    cin >> s;
    if(s.size()%2!=0){
        cout<<"No"<<endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0 && s[i] != 'h')
        {
            cout << "No" << endl;
            return 0;
        }
        else if (i % 2 == 1 && s[i] != 'i')
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
