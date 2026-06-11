#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
    int n;
    cin >> n;
    long long int ans = 1000000000;
    long long int sum = 0;
    int i, j;
    vector<long long int>x(n);
    for (i = 0; i < n; i++)
    {
        cin >> x.at(i);
    }
    for (i = 1; i <= 100; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum += (x.at(j) - i) * (x.at(j) - i);
        }
        ans = min(ans, sum);
        sum = 0;

    }
    cout << ans << endl;
    
}