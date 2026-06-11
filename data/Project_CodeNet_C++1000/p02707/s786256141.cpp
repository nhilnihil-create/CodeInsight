#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
    int n;
    cin >> n;
    int i;
    vector<int>f(n);
    for (i = 0; i < n; i++)
    {
        f.at(i) = 0;
    }
    int a;
    for (i = 1; i < n; i++)
    {
        cin >> a;
        f.at(a-1)++;
    }
    for (i = 0; i < n; i++)
    {
        cout << f.at(i) << endl;
    }

}