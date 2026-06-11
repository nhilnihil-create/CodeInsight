#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
    int n, m;
    cin >> n>>m;
    int i;
    vector<int>h(n);
    vector<int>f(n);
    int cnt = 0;
    for (i = 0; i < n; i++)
    {
        cin >> h.at(i);
        f.at(i) = 1;
    }
    int a, b;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (h.at(a - 1) > h.at(b - 1))
            f.at(b - 1) = 0;
        else if(h.at(a - 1) < h.at(b - 1))
            f.at(a - 1) = 0;
        else
        {
            f.at(b - 1) = 0;
            f.at(a - 1) = 0;
        }   
    }
    for (i = 0; i < n; i++)
    {
       // cout << h.at(i) << endl;
        if (f.at(i) == 1)
            cnt++;
    }
    cout << cnt << endl;
}