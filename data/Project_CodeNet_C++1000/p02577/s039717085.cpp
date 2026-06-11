#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <assert.h>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    ll sum;
    string s;
    cin >> s;
    for(char c : s)
    {
        sum += (int)c-48;
    }
    if(sum%9==0)cout << "Yes";
    else cout << "No";
    
}