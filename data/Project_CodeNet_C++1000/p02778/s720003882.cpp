#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>           // sorted map so O(logn)
#include <unordered_map> // O(1)
typedef long long ll;
using namespace std;

int main()
{
    string x;
    string r;
    cin >> x;
    for (int i = 0; i < x.length(); ++i)
    {
        r += 'x';
    }
    cout << r << endl;
    return 0;
}
