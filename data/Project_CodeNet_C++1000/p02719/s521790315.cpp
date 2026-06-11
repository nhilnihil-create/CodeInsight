#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <map>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    long long n,k;
    cin >> n >> k;
    cout << min(n%k, k-(n%k)) << endl;
}