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
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size()/2; i++)
    {
        if (s[i] != s[s.size()-1-i])
        {
            cnt++;
        }
        
    }
    cout << cnt << endl;
}