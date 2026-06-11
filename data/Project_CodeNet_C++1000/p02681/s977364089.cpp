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
    string s,t;
    cin >> s >> t;
    t.erase(t.size()-1);
    if (s == t)
    {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}