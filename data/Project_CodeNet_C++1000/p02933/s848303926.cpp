#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <list>
#include <cstdio>
#include <stdio.h>
#include <complex>
#include <math.h>

typedef long long ll;

using namespace std;

double pi=2*acos(0);
const int INF = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main()
{
    int a;
    string s;
    cin >> a;
    cin >> s;
    if(a>=3200) cout << s;
    else cout << "red";
    return 0;
}