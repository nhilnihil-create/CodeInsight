#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
 
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if (a+b+c >= 22)
    {
        cout << "bust" << endl;
    }else{
        cout << "win" << endl;
    }
    
}