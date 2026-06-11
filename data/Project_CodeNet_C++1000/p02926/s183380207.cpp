#include<queue>
#include<algorithm>
#include<cstdio>
#include<vector>
#include <iomanip>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
vector<P>v;

bool cmp(P a,P b)
{
    return atan2(a.second,a.first)<atan2(b.second,b.first);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
         P m;
         cin>>m.first;
         cin>>m.second;
         v.push_back(m);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0; i < n; i++)
        v.push_back(v[i]);
    long double maxN=0;
    for(int start = 0; start < n; start++)
    {
        long long x = 0LL, y = 0LL;

        for(int l = 1; l <= n; l++)
        {
            x += 1LL * v[start + l - 1].first;
            y += 1LL * v[start + l - 1].second;

            maxN = max(maxN, sqrtl(1LL * x * x + y * y));
        }
    }
    cout << fixed << setprecision(60) << maxN << '\n';
    return 0;
}
///*
//
//4 6 0
//0 1 2
//1 2 2
//1 3 1
//0 2 5
//1 3 3
//0 3 4
//
//
//
//*/
