#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <numeric>
#include <map>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if ((i+1)%2 == 1 && A[i]%2 == 1)
        {
            cnt++;
        }
        
    }
    cout << cnt << endl;
}