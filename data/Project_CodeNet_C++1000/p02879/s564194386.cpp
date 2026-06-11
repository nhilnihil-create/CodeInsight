#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    int a,b;
    cin >> a >> b;
    if (a >= 1 && a <= 9 && b >= 1 && b <= 9)
    {
        cout << a*b << endl;
    }else{
        cout << -1 << endl;
    }
    
}
    