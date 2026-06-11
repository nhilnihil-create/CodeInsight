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
    int n,m,x;
    cin >> n >> m >> x;
    vector<vector<int>> bk(n,vector<int>(m+1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            cin >> bk[i][j];
        }
        
    }
    int min = 1e9;
    for (int i = 0; i < pow(2,n); i++)
    {
        int bit = 0;
        vector<int> A(m+1);
        for (int bit = 0; bit < n; bit++)
        {
            if (i&(1<<bit))
            {
                for (int k = 0; k < m+1; k++)
                {
                    A[k] += bk[bit][k];
                }
                
            }
        }
        int cnt = 0;
        for (int i = 1; i < m+1; i++)
        {
            if (A[i] >= x)
            {
                cnt++;
            }
            
        }
        if (cnt == m && min > A[0])
        {
            min = A[0];
        }
        
    }
    if (min == 1e9)
    {
        cout << "-1" << endl;
    }else{
        cout << min << endl;
    }
    
}