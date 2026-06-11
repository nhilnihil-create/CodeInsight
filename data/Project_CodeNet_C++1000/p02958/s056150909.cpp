#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ctime>
#include <assert.h>
using namespace std;

const unsigned long long MOD = (unsigned long long)(1e9 + 7);

#define FROM_0(i, n) for(int i = 0; i < (n); i++)
#define FROM_S(i, s, e) for(int i = (s); i < (e); i++)
#define ITER_BEGIN_END(iter, vec) for(auto iter = vec.begin(); iter != vec.end(); iter++)

int main()
{
    int n;
    cin >> n;
    int diff = 0;
    FROM_0(i, n)
    {
        int x;
        cin >> x;
        diff += x == i + 1 ? 0 : 1;
    }
    cout << (diff == 0 || diff == 2 ? "YES" : "NO") << endl;
    return 0;
}
