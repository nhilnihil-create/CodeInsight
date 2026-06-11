#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
    long long int a, b;
    cin >> a >> b;
    long long int ans;
    long long int i;
    for (i = min(a, b); i <= a * b; i += min(a, b))
    {
        if (i % a == 0 && i % b == 0)
        {
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;
    
}