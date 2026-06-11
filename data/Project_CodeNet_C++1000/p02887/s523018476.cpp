#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
    int n;
    string s;
    cin >> n>>s;
    int a = 0;
    int cnt = 0;
    int b = 1;
    while (a < n&&b<n)
    {
        if (s.at(a) == s.at(b))
        {
            cnt++;
        }
        else
        {
            a = b;
        }
        b++;
    }
    cout << n-cnt << endl;
    
}