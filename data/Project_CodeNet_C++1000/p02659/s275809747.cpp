#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
const int N=1e6;
int main()
{
    ull x;

    long double y;

    cin>>x>>y;

    ull sum=0;

    y=round(y*100);

    sum=x*y;

    cout<<sum/100<<endl;




}
