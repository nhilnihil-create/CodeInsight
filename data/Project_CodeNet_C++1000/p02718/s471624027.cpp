#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <map>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> A(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum <= A[i]*4*m)
        {
            count++;
        }
    }
    if (count >= m)
    {
        cout << "Yes" << endl;
    }else
    {
        cout << "No" << endl;
    }
    
    
}