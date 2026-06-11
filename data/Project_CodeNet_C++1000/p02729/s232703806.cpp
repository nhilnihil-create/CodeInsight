#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int i,j=0,k=0;
    j=(n*(n-1))/2;
    k=(m*(m-1))/2;
    cout<<(j+k)<<endl;
}