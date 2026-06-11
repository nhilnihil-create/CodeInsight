#include <bits/stdc++.h>
using namespace std;
#define     LL      long long int
vector<int>v,vv;

int main()
{
    LL n,m;
    cin>>n>>m;
    cout<<min(n%m,m-(n%m))<<endl;

     return 0;
}
