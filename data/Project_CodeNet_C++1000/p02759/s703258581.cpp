#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<bitset>
#include<cassert>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<fstream>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
int main()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    if (n % 2 != 0)
        cout << (n / 2) + 1 << endl;
    else 
        cout << n / 2 << endl;

    return 0;
}