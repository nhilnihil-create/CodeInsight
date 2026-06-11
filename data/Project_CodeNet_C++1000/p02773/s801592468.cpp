#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

const unsigned long long BASE = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    map<string, int> table;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        map<string, int>::iterator pFind = table.find(s);
        if (pFind == table.end())
        {
            table.insert(pair<string, int>(s, 1));
            maxCount = maxCount > 1 ? maxCount : 1;
        }
        else
        {
            pFind->second++;
            maxCount = maxCount > pFind->second ? maxCount : pFind->second;
        }
    }
    for (map<string, int>::iterator pIter = table.begin(); pIter != table.end(); pIter++)
    {
        if (pIter->second == maxCount)
        {
            cout << pIter->first << endl;
        }
    }

    return 0;
}
