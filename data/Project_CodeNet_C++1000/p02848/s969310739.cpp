#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

const unsigned long long BASE = 1e9 + 7;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++)
    {
        int idx = s[i] - 'A';
        cout << char((int(s[i] - 'A') + n) % 26 + 'A');
    }
    cout << endl;
    return 0;
}
