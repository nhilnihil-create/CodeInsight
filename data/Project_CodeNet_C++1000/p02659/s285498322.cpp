#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <map>
#include <utility>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;


int main()
{
    ll a;
    double b;
    cin >> a >> b;
    int c = round(b*100);
    cout << a*c/100 << endl;
}