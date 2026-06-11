#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n);
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    for (i = 0; i < n; i++)
    {
        b.at(a.at(i)-1) = i+1;
    }
    for (i = 0; i < n-1; i++)
    {
        cout << b.at(i)<<" ";
    }
    cout << b.at(n-1) << endl;
    
}