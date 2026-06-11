#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int N, a[200000],x;

int main()
{
    int i,j;
    cin >> N;
    rep0(i,N){cin>>j; x^=j; a[i]=j;}

    rep0(i,N)
    {
       cout << (x^a[i]) << " ";
    }

    cout << endl;
    return 0;
}