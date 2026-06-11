#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <map>
#include <utility>
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    map<int, int> p;
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++)
        {
            int a;
            cin >> a;
            p[a] += 1;
        }
        
    }
    int count = 0;
    for (int i = 1; i < n+1; i++)
    {
        if (p[i] == 0)
        {
            count++;
        }
        
    }
    cout << count << endl;
}